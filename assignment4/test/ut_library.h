#ifndef UT_LIBRARY_H
#define UT_LIBRARY_H
#include "../src/library.h"

class LibraryTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        innerCollection = new Collection("innerCollection", "Items des");
        testCollection = new Collection("testCollection", "Items des");
        book1 = new Book("test1", "test des", "someone", "8785");
        book2 = new Book("test2", "test des", "someone", "8786");
        book3 = new Book("test3", "test des", "someone", "8787");
        book4 = new Book("test3", "test des", "someone", "8789");
        book5 = new Book("test5", "test des", "someone", "8790");
        testCollection->add(book1);
        testCollection->add(book3);
        testCollection->add(book4);
    }

    void TearDown() override
    {
        delete testCollection;
        delete book1;
        delete book2;
        delete book3;
        delete book4;
        delete book5;
    }
    Item *testCollection;
    Item *innerCollection;
    Item *book1;
    Item *book2;
    Item *book3;
    Item *book4;
    Item *book5;
    Library library;
};

TEST_F(LibraryTest, AddItemTest)
{
    library.add(testCollection);
    std::vector<Item *> result;
    result = library.findByName("test1");
    ASSERT_EQ(book1, result[0]);
    result = library.findByName("test3");
    ASSERT_EQ(book3, result[0]);
}

TEST_F(LibraryTest, RemoveByNameTest)
{
    library.add(testCollection);
    library.add(book5);
    library.removeByName("test2");
    ASSERT_EQ(0, library.findByName("test2").size());
    library.removeByName("test3");
    ASSERT_EQ(0, library.findByName("test3").size());
}

TEST_F(LibraryTest, ListTest)
{
    library.add(testCollection);
    library.add(book5);
    ASSERT_EQ("testCollection\ttest1\ttest3\ttest3\ttest5\t\n", library.list("name"));
    library.removeByName("test3");
    ASSERT_EQ("Collection Name: testCollection\n\tDescription: Items des\nBook Name: test1\n\tAuthor: someone\n\tDescription: test des\n\tISBN: 8785\nBook Name: test5\n\tAuthor: someone\n\tDescription: test des\n\tISBN: 8790\n\n", library.list("all"));
}

TEST_F(LibraryTest, FindByISBNTest)
{
    library.add(testCollection);
    library.add(book5);
    ASSERT_EQ(book3, library.findByISBN("8787"));
    ASSERT_EQ(book5, library.findByISBN("8790"));
}

TEST_F(LibraryTest, RemoveByISBNTest)
{
    library.add(testCollection);
    library.add(book5);
    library.add(book2);
    library.removeByISBN("8787");
    ASSERT_EQ(nullptr, library.findByISBN("8787"));
    library.removeByISBN("8789");
    ASSERT_EQ(nullptr, library.findByISBN("8789"));
    library.removeByISBN("8790");
    ASSERT_EQ(nullptr, library.findByISBN("8790"));
    ASSERT_EQ(1, testCollection->size());
}

#endif