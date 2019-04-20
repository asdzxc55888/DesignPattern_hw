#ifndef ITERATOR_H
#define ITERATOR_H

template <class T>
class Iterator {
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual T current() = 0;
};


template <class T>
class NullIterator: public Iterator<T> {
public:
    void first();
    void next();
    bool isDone() const;
    T current();
};

#endif