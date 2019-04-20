#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "item.h"
using namespace std;

class Library {
public:
    enum ListType {
        Name,
        All
    };
    void add(Item * item);
    std::vector<Item *> find() const;
    std::vector<Item *> findByName(std::string name) const;
    std::vector<Item *> findByName(std::string name,Item* item) const;
    Item * findByISBN(std::string isbn) const;
    void removeByISBN(std::string isbn);
    void removeByName(std::string name);
    std::string list(Library::ListType type=Name) const;
    std::string list(std::string type) const;
private:
    std::vector<Item *> _items;
    Library::ListType typeMap(std::string type) const;
    std::string getCollectionItems(Library::ListType type, Item *item) const;
    std::string getItemAll(Item *item) const;
};
#endif
