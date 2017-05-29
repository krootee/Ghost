class particle {
  constructor (x, y, speed, direction) {
    this.position = new vector(x, y);
    this.velocity = new vector(0,0);
    this.velocity.setLength(speed);
    this.velocity.setAngle(direction);
  }

  update() {
    this.position.addTo(this.velocity);
  }
}
