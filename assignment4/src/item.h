#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include <vector>
#include "iterator.h"

class Item
{
  protected:
    Item(std::string name, std::string description);

  public:
    virtual ~Item();
    virtual void add(Item *item);
    virtual void remove(Item *item);
    virtual void removeByName(std::string name);
    std::string name() const;
    std::string description() const;
    virtual std::string author() const;
    virtual std::string isbn() const;
    virtual int size() const;
    virtual Iterator<Item *> *createIterator();

  private:
    std::string _name;
    std::string _des;
};
#endif