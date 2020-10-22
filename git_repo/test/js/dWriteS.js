var bb = require('bonescript');
var fs = require('fs');
var http = require('http');
var socketio = require('socket.io');

var htmlPage = 'dWriteC.html';
var httpServer = http.createServer(handler);
var io = socketio.listen(httpServer);

function handler(req, res) {
	fs.readFile(htmlPage, function (err, data){
		if(err) {
			res.writeHead(500);
			return res.end('Error loading file: ' + htmlPage);
		}
		res.writeHead(200);
		res.end(data);
	});

}

httpServer.listen(8088);
io.sockets.on('connection', onConnect);
function onConnect(socket) {
	socket.on('digitalWrite', handleDigitalWrite);
}

function handleDigitalWrite(message) {
	var data = JSON.parse(message);
	console.log("pin:" + data.pin + " value:" + data.value);
	bb.pinMode(data.pin, bb.OUTPUT);
	bb.digitalWrite(data.pin, data.value);

}
