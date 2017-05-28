//https://www.youtube.com/watch?v=zYOGtlY6xaM&index=7&list=PL7wAPgl1JVvUEb0dIygHzO4698tmcwLk9
class vector {
  constructor(x, y) {
    this._x = x;
    this._y = y;
  }

  getX(){
    return this._x;
  }

  getY() {
    return this._y;
  }

  setY(value){
    this._y = value;
  }

  setX(value){
    this.x_ = value
  }

  setAngle(angle) {
    var length = this.getLength();
    this._x = Math.cos(angle) * length;
    this._y = Math.sin(angle) * length;
  }

  getAngle() {
    return Math.atan2(this._y, this._x);
  }

  setLength(length) {
    var angle = this.getAngle();
    this._x = Math.cos(angle) * length;
    this._y = Math.sin(angle) * length;
  }

  getLength() {
    return Math.sqrt(this._x * this._x + this._y * this._y);
  }

  add(v2){
    return new vector(v2.getX() + this._x, v2.getY() + this._y);
  }

  subtract(v2){
    return new vector(v2.getX() - this._x, v2.getY() - this._y);
  }

  multiply(value) {
    return new vector(this._x * value, this._y * value);
  }

  divide(value) {
    return new vector(this._x / value, this._y / value);
  }

  addTo(v2) {
    this._x += v2.getX();
    this._y += v2.getY();
  }

  subtractFrom(v2) {
    this._x -= v2.getX();
    this._y -= v2.getY();
  }

  multiplyBy(value) {
    this._x *= value;
    this._y *= value;
  }

  divideBy(value) {
    this._x /= value;
    this._y /= value;
  }
}
