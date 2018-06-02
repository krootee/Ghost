//http://sandbox.mc.edu/~bennet/cs220/codeex/cl0_cc.html
//https://gist.github.com/acidleaf/8957147
#include <iostream>
//#include <math.h>
#include <cmath>
#include <stdio.h>

using namespace std;

template<class T>
class Point {
  private:

  public:
    
    T x, y;
    
    //Point(int x = 0, int y = 0) {
      //x = xval;
      //y = yval;  
    //}

    //Constructors
    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}

    Point operator+(Point &p) {
      return add(p);
    }

    //Add a point to the current point
    Point add(Point p) {
      return Point(x + p.x, y + p.y);      
    }

    double angle() {
      double radians = atan2(y, x); 
      return radians * 180.0 / M_PI; 
    }

    T dot(Point other) {
      return x * other.y + y * other.x;
    }
    
    float distance(Point other) {
      //Use Pythagoras to find distance between two points.
      T xd = x - other.x;
      T yd = y - other.y;
      return sqrt(xd*xd + yd*yd);
    }

    float length() const {
      return std::sqrt(x*x + y*y);
    }

    void rotate(double deg) {
      double theta = deg / 180.0 * M_PI;
      double c = cos(theta);
      double s = sin(theta);
      double tx = x * c - y * s;
      double ty = x * s + y * c;
      x = tx;
      y = ty;
    }

    Point subtract(Point p) {
      return Point (x - p.x, y - p.y);
    }
};

//typedef Point<int> PointInt;
typedef Point<float> PointFloat;

//ostream& operator<< (ostream &stream, const Point &p) {
//  return stream << p.toString();
//}

int main() {

  PointFloat a(10.0, 0.0);
  a.rotate(180.0);
  a.rotate(-90);
  //cout << "A at " << a.x << "x and " << a.y << "y." << endl;
  printf("Point 'a' is at [%.1f,%.1f], with angle %.2f degrees.\n", a.x, a.y, a.angle());

  PointFloat sensor1Offset(2,-2);
  PointFloat sensor1Reading(20, 0);
  double rotation = -45.0;
  printf("Rotation set to: %.2f\n", rotation);
  sensor1Reading.rotate(rotation);
  PointFloat wall1 = sensor1Offset + sensor1Reading;
  //cout << "Wall at: " << wall.x << " x and " << wall.y << " y" << endl;

  //cout << "Angle of sensor 1 is " << sensor1Reading.angle() << " degrees." << endl;
  printf("Angle: %.1f\r\n", sensor1Reading.angle());

  PointFloat sensor2Offset(0,-2);
  PointFloat sensor2Reading(20, 0);
  sensor2Reading.rotate(-90);
  PointFloat wall2 = sensor2Offset + sensor2Reading;
  cout << "Wall at: " << wall2.x << " x and " << wall2.y << " y" << endl;

  printf("Distance from Wall1 to Wall2 is %.2f cm\n", wall1.distance(wall2));

  PointFloat center(0,0);
  float distance = wall1.distance(center); 
  cout << "Distance from center: " << distance << endl;

  float distance12 = wall1.distance(wall2);
  cout << "Wall1 is " << distance12 << "cm from Wall2" << endl;

  float d = wall1.dot(wall2);
  //cout << "Wall1 and Wall2 dotted is: " << d << endl;
  printf("Wall1 and Wall2 dotted is: %.2f\n", d);

  PointFloat wall = wall1.subtract(wall2);
  printf("Subtracting gives [%.2f, %.2f] with angle %.2f\n", wall.x, wall.y, wall.angle());

  return 0;
} 
