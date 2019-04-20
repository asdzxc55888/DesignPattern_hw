#ifndef UT_COLLECTION_H
#define UT_COLLECTION_H
#include "../src/collection.h"
#include "../src/book.h"

class CollectionTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        testCollection = new Collection("Items", "Items des");
        book1 = new Book("test1", "test des", "someone", "8785");
        book2 = new Book("test2", "test des", "someone", "8786");
        book3 = new Book("test3", "test des", "someone", "8787");
        book4 = new Book("test3", "test des", "someone", "8789");
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
    }

    Item *testCollection;
    Item *innerCollection;
    Item *book1;
    Item *book2;
    Item *book3;
    Item *book4;
};

TEST_F(CollectionTest, CollectionAddTest)
{
    ASSERT_EQ(3, testCollection->size());
}

TEST_F(CollectionTest, RemoveByNameTest)
{
    testCollection->removeByName("test1");
    ASSERT_EQ(2, testCollection->size());
    testCollection->removeByName("test3");
    ASSERT_EQ(0, testCollection->size());
}

TEST_F(CollectionTest, RemoveItemTest)
{
    testCollection->remove(book1);
    ASSERT_EQ(2, testCollection->size());
    testCollection->remove(book4);
    ASSERT_EQ(1, testCollection->size());
}

#endif