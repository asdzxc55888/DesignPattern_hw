#ifndef COLLECTION_H
#define COLLECTION_H
#include "item.h"
using namespace std;

class Collection : public Item
{
  public:
    Collection(std::string name, std::string description);
    ~Collection();
    void add(Item *item);
    void remove(Item *item);
    void removeByName(std::string name);
    int size() const;
    Iterator<Item *> *createIterator();

  private:
    std::vector<Item *> _items;
    class CollectionIterator;
};

#endif