#ifndef UT_BOOK_H
#define UT_BOOK_H
#include "../src/book.h"

TEST(BookTest, Consturction) {
    Item * testBook = new Book("test", "test des", "someone", "8787");
    ASSERT_EQ("test", testBook->name());
    ASSERT_EQ("test des", testBook->description());
    ASSERT_EQ("someone", testBook->author());
    ASSERT_EQ("8787", testBook->isbn());
}

#endif
