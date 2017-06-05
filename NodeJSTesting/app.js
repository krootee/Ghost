const express = require('express')
const app = express()


var SerialPort = require("serialport");

var io = require('socket.io')(3001);

var port = new SerialPort("/dev/ttyUSB0", {
  baudRate: 115200,
  parser: SerialPort.parsers.readline('\n')
});

port.on('open', function()  {
  port.write('main screen turn on', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message);
    }
    console.log('message written');
  });
});

port.on('error', function(err) {
  console.log('Error: ', err.message);
})

port.on('data', function(data) {
  console.log('Data' + JSON.stringify(data));
  var d = JSON.parse(data);
  console.log(d.message);
});

app.get('/style.css', function(req, res) {
  res.sendFile(__dirname + '/style.css');
});

app.get('/', function (req, res) {
  //res.send('Hello World!')
  res.sendFile(__dirname + '/index.html');
});

app.listen(3000, function () {
  console.log('Example app listening on port 3000!')
})

io.on('connection', function(socket) {
  //socket.emit('news', {hello: 'world'});
  socket.on('my other event', function(data) {
    console.log(data);
  });
  port.on('data', function(data) {
    socket.emit('news', JSON.stringify(data));
  });
});
