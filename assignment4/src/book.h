#ifndef BOOK_H
#define BOOK_H

#include "item.h"
using namespace std;

class Book: public Item {
public:
    Book(std::string name, std::string description, std::string author, std::string isbn);
    ~Book();
    std::string author() const;
    std::string isbn() const;
private:
    std::string _author;
    std::string _isbn;
};

#endif