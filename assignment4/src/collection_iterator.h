#ifndef COLLECTION_ITERATOR_H
#define COLLECTION_ITERATOR_H
#include "iterator.h"
#include "collection.h"

class Collection::CollectionIterator: public Iterator<Item *> {
public:
    CollectionIterator(Collection *collection);
    void first();
    void next();
    bool isDone() const;
    Item * current();
private:
    Collection *_collection;
    std::vector<Item *>::iterator _current;
};

#endif