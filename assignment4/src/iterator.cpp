#include "iterator.h"

class Item;
template class NullIterator<Item *>;

template <class T>
void NullIterator<T>::first() { throw "NULL Iterator cannot use first() function!"; }

template <class T>
void NullIterator<T>::next() { throw "NULL Iterator cannot use first() function!"; }

template <class T>
bool NullIterator<T>::isDone() const { return true; }

template <class T>
T NullIterator<T>::current() { return T(); }