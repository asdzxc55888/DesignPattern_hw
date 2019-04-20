#ifndef UT_ITERATOR
#define UT_ITERATOR
#include"../src/iterator.h"
#include "../src/picture.h"
#include "../src/find.h"

TEST(IteratorTest, Construction)
{
    Shape * p = new Picture();
    Iterator<Shape *> * it = p->createIterator();
}

TEST(IteratorTest, firstTest)
{
    Shape * p = new Picture();
    Shape * r = new Rectangle(4, 5);
    Shape * c = new Circle(3);
    Shape * t = new Triangle(3, 4, 5);

    p->addShape(r);
    p->addShape(c);
    p->addShape(t);

    Iterator<Shape *> * it = p->createIterator();
    it->first();
    ASSERT_EQ(20, it->current()->area());
}

TEST(IteratorTest, nextTest)
{
    Shape * p = new Picture();
    Shape * r = new Rectangle(4, 5);
    Shape * c = new Circle(3);
    Shape * t = new Triangle(3, 4, 5);

    p->addShape(r);
    p->addShape(c);
    p->addShape(t);

    Iterator<Shape *> * it = p->createIterator();
    it->first();
    it->next();
    ASSERT_NEAR(9*3.14, it->current()->area(), 0.1);
}

TEST(IteratorTest, isDoneTest)
{
    Shape * p = new Picture();
    Shape * r = new Rectangle(4, 5);
    Shape * c = new Circle(3);
    Shape * t = new Triangle(3, 4, 5);

    p->addShape(r);
    p->addShape(c);
    p->addShape(t);

    Iterator<Shape *> * it = p->createIterator();
    it->first();
    it->next();
    it->next();
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST(IteratorTest, NullIteratorTest)
{
    Shape * r = new Rectangle(4, 5);
    
    Iterator<Shape *> * it = r->createIterator();
    
    ASSERT_TRUE(it->isDone());
    ASSERT_ANY_THROW(it->first());
    ASSERT_ANY_THROW(it->next());
    //ASSERT_EQ(20 ,it->current()->area());
}

TEST(IteratorTest, FindTest)
{
    Shape * p = new Picture();
    Shape * r = new Rectangle(4, 5);
    Shape * r2 = new Rectangle(4, 5);
    Shape * c = new Circle(3);
    Shape * c2 = new Circle(3);
    Shape * c3 = new Circle(3);
    Shape * t = new Triangle(3, 4, 5);

    p->addShape(r);
    p->addShape(r2);
    p->addShape(c);
    p->addShape(c2);
    p->addShape(c3);
    p->addShape(t);
    std::vector<Shape*> Rresult = findByShape(p, std::string("rectangle"));
    std::vector<Shape*> Cresult = findByShape(p, std::string("circle"));
    std::vector<Shape*> Tresult = findByShape(p, std::string("triangle"));
    ASSERT_EQ(2, Rresult.size());
    ASSERT_EQ(3, Cresult.size());
    ASSERT_EQ(1, Tresult.size());
}

#endif
