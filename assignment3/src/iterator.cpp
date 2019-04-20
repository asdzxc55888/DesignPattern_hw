#include "iterator.h"
#include "picture.h"

template <class Item>
void NullIterator<Item>::first() { throw "NULL Iterator cannot use first() function!"; }

template <class Item>
void NullIterator<Item>::next() { throw "NULL Iterator cannot use first() function!"; }

template <class Item>
bool NullIterator<Item>::isDone() const { return true; }

template <class Item>
Item NullIterator<Item>::current() { return Item(); }

PictureIterator::PictureIterator(Picture * picture): _picture(picture){}

void PictureIterator::first() {
    _current = _picture->_shapes.begin();
}

void PictureIterator::next() {
    ++_current;
}

bool PictureIterator::isDone() const {
    return _current == _picture->_shapes.end();
}

Shape * PictureIterator::current() { return *_current; }

template class NullIterator<Shape *>;
