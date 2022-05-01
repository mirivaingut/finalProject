// const exp = require('express');
// const app = exp();
// const port = 3500;

// const net=require('net');

// app.listen(port, () => console.log(`server is listening in http://localhosto:${port}`));

// app.get('/',(res,req)=>{
//     console.log("connected!!!!!!!!!!!!");
// });

//----------------------------------------------------

// const net = require('net');

// const server = net.createServer((c) => {
//   // 'connection' listener.
//   console.log('client connected');
//   c.on('end', () => {
//     console.log('client disconnected');
//   });
//   c.write('hello\r\n');
//   c.pipe(c);
// });

// server.on('error', (err) => {
//   throw err;
// });

// server.listen(3500, () => {
//   console.log('server bound');
//   console.log(server.);
// });

//-------------------------------------------------------

// var net = require('net');

// var server = net.createServer(function(socket) {
// 	socket.write('Echo server\r\n');
// 	socket.pipe(socket);
// });

// server.listen(3500, 'localhost',()=>{
//     console.log("listen...");
// });

// server.on('connection',(sock)=>{
//     console.log('connection......');
//     sock.write('we connected!!!!!!!!!!');
// })

//--------------------------------------------------

// Include Nodejs' net module.
const Net = require('net');
const { stringify } = require('querystring');
// The port on which the server is listening.
const port = 80;

// Use net.createServer() in your code. This is just for illustration purpose.
// Create a new TCP server.

// const server = new Net.Server();
const server = new Net.createServer();
// The server listens to a socket for a client to make a connection request.
// Think of a socket as an end point.
server.listen(port, function () {
    console.log(`Server listening for connection requests on socket localhost:${port}`);
});

// When a client requests a connection with the server, the server creates a new
// socket dedicated to that client.
server.on('connection', function (socket) {
    console.log('A new connection has been established.');

    // Now that a TCP connection has been established, the server can send data to
    // the client by writing to its socket.
    socket.write('Hello, client.');

    // The server can also receive data from the client by reading from its socket.
    socket.on('data', function (buffer,) {
        console.log(`Data received from client: ${buffer.toString()}`);
        console.log("The message Type: ",(buffer[2] == String.fromCharCode(2)) ? "discovery" : "source");
        if (buffer[3] == "1") {
            console.log("The status: ", parseInt(JSON.stringify(buffer).substring(5)));
        } else {
            console.log("The distance: ", String.fromCharCode(JSON.stringify(buffer).substring((4, 12))));
            console.log("The angle: ", parseInt(JSON.stringify(buffer).substring((4, 12))));
            console.log("The speed: ", parseInt(JSON.stringify(buffer).substring((4, 12))));
        }
    });

    // When the client requests to end the TCP connection with the server, the server
    // ends the connection.
    
    socket.on('end', function () {
        console.log('Closing connection with the client');
    });

    // Don't forget to catch error, for your own sake.
    socket.on('error', function (err) {
        console.log(`Error: ${err}`);
    });
});
