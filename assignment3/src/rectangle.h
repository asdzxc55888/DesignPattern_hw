#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
public:
  Rectangle(double width, double length) {
    _w = width;
    _l = length;
  }
  double getWidth() const {return _w;}
  double getLength() const {return _l;}
  double area() const {
    return _w * _l;
  }
  double perimeter() const {
      return 2 * (_w + _l);
  }
  std::string getName() const{
      return std::string("rectangle");
  }
private:
  double _w;
  double _l;
};

#endif
