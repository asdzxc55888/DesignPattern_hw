#include "item.h"

Item::Item(std::string name, std::string description) : _name(name), _des(description) {}

Item::~Item()
{
}
void Item::add(Item *item)
{
    throw("Item cannot use add function!");
}
void Item::remove(Item *item)
{
    throw("Item cannot use remove function!");
}
void Item::removeByName(std::string name)
{
    throw("Item cannot use removeByName function!");
}
std::string Item::name() const
{
    return _name;
}
std::string Item::description() const
{
    return _des;
}
std::string Item::author() const
{
    throw("Item cannot get author");
}
std::string Item::isbn() const
{
    throw("Item cannot get isbn");
}
int Item::size() const
{
    return 1;
}
Iterator<Item *> *Item::createIterator()
{
    NullIterator<Item *> * it = new NullIterator<Item *>();
    return it;
}