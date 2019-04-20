#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
#include "shape.h"
#include "picture.h"

class Picture: public Shape {
    friend class PictureIterator;

public:
    void addShape(Shape *s) {
        _shapes.push_back(s);
    }

    double area() const {
        double totalArea = 0;
        for(int i=0; i < _shapes.size(); ++i) {
            totalArea += _shapes[i]->area();
        }
        return totalArea;
    }

    double perimeter() const {
        double totalPerimeter = 0;
        for (int i = 0; i < _shapes.size(); ++i) {
            totalPerimeter += _shapes[i]->perimeter();
        }
        return totalPerimeter;
    }

    Iterator<Shape *> * createIterator() {
        Iterator<Shape *> *it;
        it = new PictureIterator(this);
        return it;
    }

    std::string getName() const{
        return std::string("picture");
    }
private:
    std::vector<Shape *> _shapes;
};

#endif
