#ifndef IO_H
#define IO_H
#include <string>
#include "library.h"
void printInstructions();
void handleInstructions(std::string instruction, Library &library);
Item * addBookInstructions();
Item * addCollectionInstructions();
void removeBook(Library & library);
void removeCollection(Library & library);
void listBooksInfo(Library & library);
void listBooksInfoDetail(Library & library);

#endif
