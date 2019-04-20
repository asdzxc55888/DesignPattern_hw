#ifndef FIND_H
#define FIND_H

#include <vector>
#include <string>
#include <iostream>
#include "shape.h"
#include "circle.h"
#include "triangle.h"
#include "iterator.h"

std::vector<Shape *> findByShape(Shape * sp, std::string name) {
    std::vector<Shape *> result;
    Iterator<Shape*> *it = sp->createIterator();

    for(it->first(); !it->isDone(); it->next())
    {
        if(it->current()->getName() == name)
        {
            result.push_back(it->current());
        }
    }
    return result;
}

#endif
