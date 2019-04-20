#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
#include "shape.h"

class Picture: public Shape {
public:
    void addShape(Shape *s) 
    {
        shapes.push_back(s);
    }

    double area() const 
    { 
        double result = 0;
        for(int i = 0; i < shapes.size(); i++)
        {
            result += shapes[i]->area();
        }
        return result; 
    }

    double perimeter() const 
    { 
        double result = 0;
        for(int i = 0; i < shapes.size(); i++)
        {
            result += shapes[i]->perimeter();
        }
        return result; 
    }

private:
    std::vector<Shape *> shapes;
};

#endif
