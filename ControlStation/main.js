window.onload = function() {
  var canvas = document.getElementById("canvas"),
    context = canvas.getContext("2d"),
    width = canvas.width = window.innerWidth,
    height = canvas.height = window.innerHeight;

    var centerY = height * .5;
    var centerX = width * .5;
    var offset = height * .5;
    var speed = 0.02;
    var angle = 0;
    var carSize = 50;
    var carRatio = 2.3;

    var v = new vector(50,100);
    v.setAngle(90);
    console.log("Length: " + v.getX());

    //Add vectors
    var v1 = new vector(10,5);
    var v2 = new vector(3,4);
    var v3 = v1.add(v2);
    console.log(v3.getX(), v3.getY());

    //Multiply vectors
    var v4 = v1.multiply(2);
    console.log(v1.getLength());
    console.log(v4.getLength());

    v1.addTo(v4);
    console.log(v1.getLength());

    v1.divideBy(2);
    console.log(v1.getLength());

    //drawVector(v);


    render();
    drawRaceTrack();
    //
    // function drawVector(va) {
    //   ve = Object.create(vector, va);
    //   var centerX = this.width / 2;
    //   var centerY = this.height / 2;
    //
    //   context.beginPath();
    //   context.moveTo(centerX, centerY);
    //   context.lineTo(centerX + 100, centerY + ve.getY());
    //   context.stroke();
    //   requestAnimationFrame(drawVector);
    //
    // }

    function drawRaceTrack() {
      context.beginPath();
      context.moveTo(20,20);
      for (var i = 0; i < 100; i++) {
        context.lineTo(i+20+Math.random()*10, i+20);
      }
      context.stroke();
      requestAnimationFrame(drawRaceTrack);
    }

    function render() {
      var y = centerY + Math.sin(angle) * offset;
      context.clearRect(0,0,width, height);
      context.beginPath();
      //context.arc(centerX, y, 50, 0, Math.PI * 2, false);
      context.fillRect(centerX, y+200, carSize/10, carSize/10);
      context.moveTo(centerX, y);
      context.lineTo(centerX - 75, y - 75);
      context.moveTo(centerX+20, y);
      context.lineTo(centerX+20 - 75, y - 75);
      context.stroke();
      //context.fillStyle = "black";
      //context.fill();

      context.fillRect(centerX, y, carSize, carSize*carRatio);
      //context.fillStyle = "rgba(200,0,0,.3)";
      context.fillStyle = "green";
      context.fill();

      angle += speed;
      requestAnimationFrame(render);
    }
}
