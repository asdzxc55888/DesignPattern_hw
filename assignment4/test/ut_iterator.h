#ifndef UT_ITERATOR_H
#define UT_ITERATOR_H
#include "../src/iterator.h"
#include "../src/collection_iterator.h"

class IteratorTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        innerCollection = new Collection("Items2", "Items des");
        testCollection = new Collection("Items", "Items des");
        book1 = new Book("test1", "test des", "someone", "8785");
        book2 = new Book("test2", "test des", "someone", "8786");
        book3 = new Book("test3", "test des", "someone", "8787");
        book4 = new Book("test3", "test des", "someone", "8789");
        testCollection->add(book1);
        testCollection->add(book3);
        innerCollection->add(book2);
        testCollection->add(innerCollection);
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

TEST_F(IteratorTest, NullIteratorTest)
{
    Iterator<Item*>* it = book1->createIterator();
    ASSERT_ANY_THROW(it->first());
    ASSERT_ANY_THROW(it->next());
    ASSERT_TRUE(it->isDone());
    ASSERT_EQ(nullptr, it->current());
}

TEST_F(IteratorTest, FirstTest)
{
    Iterator<Item*>* it = testCollection->createIterator();
    it->first();
    ASSERT_EQ(book1, it->current());
}

TEST_F(IteratorTest, IsDoneTest)
{
    Iterator<Item*>* it = testCollection->createIterator();
    it->first();
    it->next();
    ASSERT_FALSE(it->isDone());
    it->next();
    it->next();
    it->next();
    ASSERT_TRUE(it->isDone());
}
#endif