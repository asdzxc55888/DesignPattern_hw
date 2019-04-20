#include <iostream>
#include <cctype>
#include <regex>
#include "io.h"
#include "library.h"
#include "book.h"
#include "collection.h"

void printInstructions()
{
    std::cout << "Please enter the instruction as following to manage the library: " << std::endl;
    std::cout << "\t1. 'Add book': to add book to the library" << std::endl;
    std::cout << "\t2. 'Add collection': to add a collection to the library" << std::endl;
    std::cout << "\t3. 'Remove book': to remove a book from the library" << std::endl;
    std::cout << "\t4. 'Remove collection': to remove a collection from the library" << std::endl;
    std::cout << "\t5. 'list': to list all the items in the library" << std::endl;
    std::cout << "\t6. 'list all': to list the detail of all the items in the library" << std::endl;
    std::cout << "\t7. 'exit': to exit the program." << std::endl;
}
void handleInstructions(std::string instruction, Library &library)
{
    if (instruction == "Add book")
    {
        library.add(addBookInstructions());
    }
    else if (instruction == "Add collection")
    {
        library.add(addCollectionInstructions());
    }
    else if (instruction == "Remove book")
    {
        removeBook(library);
    }
    else if (instruction == "Remove collection")
    {
        removeCollection(library);
    }
    else if (instruction == "list")
    {
        listBooksInfo(library);
    }
    else if (instruction == "list all")
    {
        listBooksInfoDetail(library);
    }
    else if (instruction == "exit")
    {
        std::exit(1);
    }
    else
    {
        std::cout << "error command !!!" << std::endl;
    }
}
Item *addBookInstructions()
{
    std::string name, des, author, isbn;
    std::cout << "Please enter the infomations of books: " << std::endl;
    std::cout << "Name of book: ";
    std::getline(std::cin, name, '\n');
    std::cout << "Description of book: ";
    std::getline(std::cin, des, '\n');
    std::cout << "Author of book: ";
    std::getline(std::cin, author, '\n');
    std::cout << "ISBN of book: ";
    std::getline(std::cin, isbn, '\n');
    Item *newBook = new Book(name, des, author, isbn);
    return newBook;
}
Item *addCollectionInstructions()
{
    regex reg("^[0-9]$");
    std::string name, des, bookNumber;
    int bookNumInt = 0;
    std::cout << "Please enter the infomations of collection: " << std::endl;
    std::cout << "Name of collection: ";
    std::getline(std::cin, name, '\n');
    std::cout << "Description of collection: ";
    std::getline(std::cin, des, '\n');
    std::cout << "Number of books in the collection: ";
    std::getline(std::cin, bookNumber, '\n');
    if (regex_match(bookNumber, reg))
    {
        bookNumInt = atoi(bookNumber.c_str());
    }

    Item *newCollection = new Collection(name, des);

    for (int i = 0; i < bookNumInt; i++)
    {
        newCollection->add(addBookInstructions());
    }
    return newCollection;
}
void removeBook(Library &library)
{
    std::string removeBy = "";
    std::cout << "Do you want to remove the book by name or ISBN? (Enter \"name\" or \"ISBN\"): ";
    std::getline(std::cin, removeBy, '\n');
    if (removeBy == "name")
    {
        std::string removeName;
        std::cout << "Enter the name of the book to remove: ";
        std::getline(std::cin, removeName, '\n');
        library.removeByName(removeName);
    }
    else if (removeBy == "ISBN")
    {
        std::string removeISBN;
        std::cout << "Enter the ISBN of the book to remove: ";
        std::getline(std::cin, removeISBN, '\n');
        library.removeByISBN(removeISBN);
    }
    else
    {
        std::cout << "error input !!!" << endl;
    }
}
void removeCollection(Library &library)
{
    std::string removeName;
    std::cout << "Enter the name of the collection to remove: ";
    std::getline(std::cin, removeName, '\n');
    library.removeByName(removeName);
}
void listBooksInfo(Library &library)
{
    std::cout << library.list() << std::endl;
}
void listBooksInfoDetail(Library &library)
{
    std::cout << library.list("all") << std::endl;
}
