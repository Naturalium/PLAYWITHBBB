//simpleWebsServer.js


var http = require('http');
var server = http.createServer(handler);
function handler(req, res){
	res.writeHead(200, {'Content-Type': 'text/plain'});
	res.end('Hello from the Beaglebone Black!\n');
	}
server.listen(8088);
console.log('Web Server running at BBB!');

