#include "collection.h"
#include "collection_iterator.h"

Collection::Collection(string name, string des) : Item(name,des) {}

Collection::~Collection(){}

void Collection::add(Item * item)
{
    _items.push_back(item);
}

void Collection::remove(Item * item)
{
    vector<Item *>::iterator it;
    for(it = _items.begin(); it != _items.end(); it++)
    {
        if((*it) == item)
        {
            it = _items.erase(it);
            it--; 
        }
    }
}

void Collection::removeByName(std::string name)
{
    vector<Item *>::iterator it;
    for(it = _items.begin(); it != _items.end(); it++)
    {
        if((*it)->name() == name)
        {
           it =  _items.erase(it);
           it--;
        }
    }
}

int Collection::size() const
{
    int result = 0;
    for(int i = 0; i < _items.size(); i++)
    {
        result += _items[i]->size();
    }
    return result;
}

Iterator<Item*>* Collection::createIterator()
{
    Iterator<Item*>* it;
    it = new CollectionIterator(this);
    return it;
}