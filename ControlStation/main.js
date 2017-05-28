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

    render();
    drawRaceTrack();

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
      context.fillRect(centerX, y, carSize, carSize*carRatio);
      context.fillStyle = "rgba(200,0,0,.3)";
      context.fill();

      angle += speed;
      requestAnimationFrame(render);
    }

}
