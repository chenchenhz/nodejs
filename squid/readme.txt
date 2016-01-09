reference:
https://help.ubuntu.com/lts/serverguide/squid.html

to change port:
edit http_port line

to change ip binding:
edit acl section. e.g.: acl fortytwo_network src 192.168.42.0/24
then edit http_access section, e.g. add http_access allow fortytwo_network

restart after change
