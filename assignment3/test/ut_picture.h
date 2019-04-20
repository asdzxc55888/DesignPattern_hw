#ifndef UT_CANVAS_H
#define UT_CANVAS_H
#include <cmath>
#include "../src/picture.h"
TEST(ShapeTest, canvas) {
    Picture p;
    ASSERT_NEAR(0, p.area(), epsilon);
    ASSERT_NEAR(0, p.perimeter(), epsilon);
}

TEST(ShapeTest, addShape) {
    Shape * p = new Picture();
    Shape * r = new Rectangle(4, 5);
    Shape * c = new Circle(3);
    Shape * t = new Triangle(3, 4, 5);

    p->addShape(r);
    p->addShape(c);
    p->addShape(t);

    double expectArea = 4 * 5 + 3 * 3 * M_PI + 3 * 2;
    double expectPerimeter = (4 + 5) * 2 + 3 * 2 * M_PI + 3 + 4 + 5;
    ASSERT_NEAR(expectArea, p->area(), epsilon);
    ASSERT_NEAR(expectPerimeter, p->perimeter(), epsilon);
}

TEST(ShapeTest, addShapeException) {
    Shape *c = new Circle(3);
    Shape *r = new Rectangle(3, 4);
    ASSERT_ANY_THROW(c->addShape(r));
}

TEST(ShapeTest, addShapeRecursive) {
    Shape * p1 = new Picture();
    Shape * r1 = new Rectangle(4, 5);
    Shape * c = new Circle(3);
    Shape * t = new Triangle(3, 4, 5);
    p1->addShape(r1);
    p1->addShape(c);
    p1->addShape(t);

    Shape * p2 = new Picture();
    Shape * r2 = new Rectangle(1, 2);
    p2->addShape(p1);
    p2->addShape(r2);

    double expectArea = 4 * 5 + 3 * 3 * M_PI + 3 * 2 + 1 * 2;
    double expectPerimeter = (4 + 5) * 2 + 3 * 2 * M_PI + 3 + 4 + 5 + (1 + 2) * 2;
    ASSERT_NEAR(expectArea, p2->area(), epsilon);
    ASSERT_NEAR(expectPerimeter, p2->perimeter(), epsilon);
}
#endif
