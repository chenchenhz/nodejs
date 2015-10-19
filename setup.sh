# Start Xvfb
Xvfb :1 -screen 0 1600x1200x24 >>/home/cheche/xvfb 2>&1 &
export DISPLAY=:1.0

# Start node server
node first.js >>/home/cheche/first_log &




