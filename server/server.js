const Net = require('net');
const { stringify } = require('querystring');

const port = 80;

const server = new Net.createServer();

function parseBuffer(buffer) {
    let message = {}
    message.type = buffer[0];
    console.log("message.type ", message.type);
    let tmp = buffer.slice(2)
    if (message.type == 1) {
        message.status = Buffer.from(tmp).readInt8(0)
    } else {
        message.distance = Buffer.from(tmp).readFloatLE(0);
        message.angle = Buffer.from(tmp).readFloatLE(4);
        message.speed = Buffer.from(tmp).readFloatLE(8);
    }
    console.log(message);
}

server.listen(port, function () {
    console.log(`Server listening for connection requests on socket localhost:${port}`);
});

server.on('connection', function (socket) {
    console.log('A new connection has been established.');
    socket.on('data', function (buffer) {
        // for (let index = 0; index < buffer.length; index++) {
        console.log(`Data received from client: ${buffer.toString()}`);
        parseBuffer(buffer)
    });

    socket.on('close', function () {
        console.log('Closing connection with the client');
    });

    socket.on('error', function (err) {
        console.log(`Error: ${err}`);
    });
});
