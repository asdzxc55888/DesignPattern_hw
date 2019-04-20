#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>

class Picture;
class Shape;

template <class Item>
class Iterator {
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual Item current() = 0;
};

template <class Item>
class NullIterator: public Iterator<Item> {
public:
    void first();
    void next();
    bool isDone() const;
    Item current();
};

class PictureIterator: public Iterator<Shape *> {
public:
    PictureIterator(Picture * picture);
    void first();
    void next();
    bool isDone() const;
    Shape* current();
private:
    Picture * _picture;
    std::vector<Shape *>::iterator _current;
};
#endif
