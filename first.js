var fs = require('fs');
var http = require('http');
var dispatcher = require('httpdispatcher');
var exec = require('child_process').exec;


const PORT=8080;
function handleRequest(request, response){
    dispatcher.dispatch(request, response);
}

var server = http.createServer(handleRequest);
server.listen(PORT, function(){
    console.log("server started");
});

dispatcher.onGet("/p", function(req, res){
    var cmd = "import -window 'Figure 1' sc.png";
    exec(cmd, function(error,stdout, stderr){
	console.log("call cmd " + cmd);
	console.log(stdout);
	console.log(stderr);
	console.log("end of output");
    });
    var img = fs.readFileSync('./sc.png');
    res.writeHead(200, {'Content-Type':'image/png','cache-control':'no-cache'});
    res.end(img, "binary");
});
