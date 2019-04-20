#include "collection_iterator.h"

Collection::CollectionIterator::CollectionIterator(Collection * collection) : _collection(collection){}

void Collection::CollectionIterator::first()
{
    _current = _collection->_items.begin();
}

void Collection::CollectionIterator::next()
{
    ++_current;
}

bool Collection::CollectionIterator::isDone() const
{
    return _current == _collection->_items.end();
}

Item *Collection::CollectionIterator::current()
{
    return *_current;
}