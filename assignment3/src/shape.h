#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "iterator.h"

class Shape {
public:
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual void addShape(Shape * s) {
      throw std::string("Not composite shape!");
  }
  virtual Iterator<Shape *> * createIterator() {
    NullIterator<Shape*> * it = new NullIterator<Shape*>();
    return it;
  }
  virtual std::string getName() const = 0;
};

#endif
