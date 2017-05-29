// https://www.youtube.com/watch?v=IpN4NLDpWDY&list=PL7wAPgl1JVvUEb0dIygHzO4698tmcwLk9&index=8
window.onload = function() {
  var canvas = document.getElementById("canvas"),
    context = canvas.getContext("2d"),
    width = canvas.width = window.innerWidth,
    height = canvas.height = window.innerHeight;

    //var position = new vector(100, 100);
    //var velocity = new vector(0,0);
    var p = new particle(100, 100, 3, Math.PI / 6);
    var car = new particle(50, 50, 2, Math.PI / 5);

    var particles = [];
    var numParticles = 100;

    for (var i = 0; i < numParticles; i++) {
      particles.push(new particle(width / 2, height / 2, Math.random()*4 + 1, Math.random() * Math.PI * 2));
    }

    // velocity.setLength(3);
    // velocity.setAngle(Math.PI / 6);

    update();

    function update(){
      context.clearRect(0, 0, width, height);

      //var velocity = new vector(1, -1);
      //position = position.add(velocity);
      //position.addTo(velocity);

      p.update();
      car.update();

      for (var i = 0; i < numParticles-1; i++) {
        var a = particles[i];
        a.update();

      context.beginPath();
      // context.arc(p.position.getX(), p.position.getY(), 10, 0, Math.PI * 2, false);
      // context.arc(p.position.getX(), p.position.getY(), 10, 0, Math.PI * 2, false);
       context.arc(a.position.getX(), a.position.getY(), 10, 0, Math.PI * 2, false);
      context.fill();
    }

      requestAnimationFrame(update);
    }

  }
