#include "library.h"

void Library::add(Item *item)
{
    _items.push_back(item);
}
std::vector<Item *> Library::find() const
{
    return _items;
}
std::vector<Item *> Library::findByName(std::string name) const
{
    vector<Item *> *result = new vector<Item *>();
    for (int i = 0; i < _items.size(); i++)
    {
        std::vector<Item *> itemResult = findByName(name, _items[i]);
        if (itemResult.size() > 0)
            result->insert(result->end(), itemResult.begin(), itemResult.end());
    }
    return *result;
}
std::vector<Item *> Library::findByName(std::string name, Item *item) const
{
    vector<Item *> *result = new vector<Item *>();
    Iterator<Item *> *it = item->createIterator();
    try
    {
        it->first();
    }
    catch (char const *e)
    {
        if (item->name() == name)
        {
            result->push_back(item);
        }
    }
    while (!it->isDone())
    {
        std::vector<Item *> itemResult = findByName(name, it->current());
        if (itemResult.size() > 0)
            result->insert(result->end(), itemResult.begin(), itemResult.end());
        it->next();
    }
    return *result;
}
Item *Library::findByISBN(std::string isbn) const
{
    for (int i = 0; i < _items.size(); i++)
    {
        Iterator<Item *> *it = _items[i]->createIterator();
        try
        {
            if (_items[i]->isbn() == isbn)
                return _items[i];
        }
        catch (char const *e)
        {
            it->first();
        }
        while (!it->isDone())
        {
            try
            {
                if (it->current()->isbn() == isbn)
                    return it->current();
            }
            catch (char const *e)
            {
            }
            it->next();
        }
    }
    return nullptr;
}
void Library::removeByISBN(std::string isbn)
{
    for (int i = 0; i < _items.size(); i++)
    {
        Iterator<Item *> *it = _items[i]->createIterator();
        try
        {
            if (_items[i]->isbn() == isbn)
            {
                _items.erase(_items.begin() + i);
                i = -1;
            }
        }
        catch (char const *e)
        {
            it->first();
        }
        while (!it->isDone())
        {
            try
            {
                if (it->current()->isbn() == isbn)
                {
                    _items[i]->remove(it->current());
                    it->first();
                }
            }
            catch (char const *e)
            {
            }
            it->next();
        }
    }
}
void Library::removeByName(std::string name)
{
    for (int i = 0; i < _items.size(); i++)
    {
        if (_items[i]->name() == name)
        {
            _items.erase(_items.begin() + i);
        }
        try
        {
            _items[i]->removeByName(name);
        }
        catch (char const *e)
        {
        }
    }
}
std::string Library::list(Library::ListType type) const
{
    std::string result = "";
    for (int i = 0; i < _items.size(); i++)
    {
        if (type == Name)
        {
            result += _items[i]->name() + "\t";
            result += getCollectionItems(type, _items[i]);
        }
        else if (type == All)
        {
            result += getItemAll(_items[i]);
            result += getCollectionItems(type, _items[i]);
        }
    }
    result += "\n";
    return result;
}
std::string Library::list(std::string type) const
{
    if (type == "name" || type == "Name")
    {
        return list();
    }
    else if (type == "all" || type == "All")
    {
        return list(All);
    }
    throw("error input");
}

std::string Library::getCollectionItems(Library::ListType type, Item *item) const
{
    std::string result = "";
    Iterator<Item *> *it = item->createIterator();
    try
    {
        it->first();
    }
    catch (char const *e)
    {
    }
    if (type == Name)
    {
        while (!it->isDone())
        {
            result += it->current()->name() + "\t";
            it->next();
        }
    }
    else if (type == All)
    {
        while (!it->isDone())
        {
            result += getItemAll(it->current());
            it->next();
        }
    }
    return result;
}

std::string Library::getItemAll(Item *item) const
{
    std::string result = "";
    try
    {
        item->author();
        result += "Book Name: " + item->name() + "\n";
        result += "\tAuthor: " + item->author() + "\n";
        result += "\tDescription: " + item->description() + "\n";
        result += "\tISBN: " + item->isbn() + "\n";
    }
    catch (char const *e)
    {
        result += "Collection Name: " + item->name() + "\n";
        result += "\tDescription: " + item->description() + "\n";
    }

    return result;
}