#include "book.h"

Book::Book(string name, string description, string author, string isbn) : Item(name, description), _author(author), _isbn(isbn) {}

Book::~Book() {}

string Book::author() const
{
    return _author;
}

string Book::isbn() const
{
    return _isbn;
}