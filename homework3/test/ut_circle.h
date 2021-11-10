#include "../src/circle.h"
#include <cmath>
#include "../src/iterator/iterator.h"

/* Follow the Homework 1 */
TEST(Circle, TestCircle){
  Circle circle(10.0);
  ASSERT_NEAR(314.159, circle.area(), 0.001);
  ASSERT_NEAR(62.8319, circle.perimeter(), 0.001);
  ASSERT_EQ("Circle (10.00)", circle.info());
}

TEST(Circle, TestCirclefail){
  try {
    Circle(0);
  }catch(std::string e) {
      ASSERT_EQ("This is not a circle!", e);
  }
  ASSERT_NO_THROW(Circle(1));
}

TEST(CaseCirecle, Create1){
    Circle circle(10.0);
    ASSERT_EQ(typeid(circle), typeid(Circle));
}

TEST(CaseCircle, GetArea){
    Circle circle(10.0);
    ASSERT_NEAR(circle.area(), 10.0*10.0*M_PI, 0.001);
};

TEST(CaseCircle, GetPerimeter){
    Circle circle(10.0);
    ASSERT_NEAR(circle.perimeter(), 10.0*2*M_PI, 0.001);
}

TEST(CaseCircle, GetInfo){
    Circle circle(10.0);
    ASSERT_EQ(circle.info(), "Circle (10.00)");
}

TEST(CaseCircle, GetZeroException){
    try{
        Circle circle(0.0);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("This is not a circle!", msg);
    }
}

TEST(CaseCircle, GetNegativeException){
    try{
        Circle circle(-5.0);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("This is not a circle!", msg);
    }
}

/* Other operation (e.g., add, delete) */

TEST(CaseCircle, AddShapeException){
    Shape* circle = new Circle(5.0);
    Shape* circle2 = new Circle(3.0);
    try{
        circle->addShape(circle2);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("You don't have method of addShape.", msg);
    }
}

TEST(CaseCircle, DeleteShapeException){
    Shape* circle = new Circle(5.0);
    Shape* circle2 = new Circle(3.0);
    try{
        circle->deleteShape(circle2);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("You don't have method of deleteShape.", msg);
    }
}

TEST(CaseCircle, IsDoneOfIteratorShouldBeTrue){
    Shape* circle = new Circle(5.0);
    Iterator* nit = circle->createIterator();
    
    ASSERT_TRUE(nit->isDone());
}

TEST(CaseCircle, CurrentItemOfIteratorShouldBeThrowException){
    Shape* circle = new Circle(5.0);
    Iterator* nit = circle->createIterator();
    
    try{
        nit->currentItem();
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The currentItem method of Null Iterator is not allowed.", msg);
    }
}