
#include "../src/rectangle.h"

/* Follow the Homework 1 */

TEST(Rectangle, TestRectangle){
  Rectangle rectangle(3.712, 4);
  ASSERT_EQ(14.848, rectangle.area());
  ASSERT_EQ(15.424, rectangle.perimeter());
  ASSERT_EQ("Rectangle (3.71 4.00)", rectangle.info());
}

TEST(Rectangle, TestRectanglefail){
  try {
    Rectangle(0, 1);
  }catch(std::string e) {
      ASSERT_EQ("This is not a rectangle!", e);
  }
  ASSERT_NO_THROW(Rectangle(1, 1));
}

TEST(CaseRectangle, Create){
    Rectangle rectangle(10.0, 5.0);
    ASSERT_EQ(typeid(rectangle), typeid(Rectangle));
}

TEST(CaseRectangle, GetArea){
    Rectangle rectangle(10.0, 5.0);
    ASSERT_NEAR(rectangle.area(), 10.0*5.0, 0.001);
};

TEST(CaseRectangle, GetPerimeter){
    Rectangle rectangle(10.0, 5.0);
    ASSERT_NEAR(rectangle.perimeter(), (10.0+5.0)*2.0, 0.001);
}

TEST(CaseRectangle, GetInfo){
    Rectangle rectangle(10.256, 5.544);
    ASSERT_EQ(rectangle.info(), "Rectangle (10.26 5.54)");
}

TEST(CaseRectangle, LengthZeroException){
    try{
        Rectangle retangle(0.0, 5.0);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("This is not a rectangle!", msg);
    }
}

TEST(CaseRectangle, LengthNegativeException){
    try{
        Rectangle retangle(-5.0, 5.0);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("This is not a rectangle!", msg);
    }
}

TEST(CaseRectangle, WidthZeroException){
    try{
        Rectangle retangle(5.0, 0.0);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("This is not a rectangle!", msg);
    }
}

TEST(CaseRectangle, WidthNegativeException){
    try{
        Rectangle retangle(5.0, -5.0);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("This is not a rectangle!", msg);
    }
}

/* other operations */

TEST(CaseRectangle, AddShapeException){
    Shape* rectangle = new Rectangle(5.0, 5.0);
    Shape* rectangle2 = new Rectangle(3.0, 3.0);
    try{
        rectangle->addShape(rectangle2);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("You don't have method of addShape.", msg);
    }
}

TEST(CaseRectangle, DeleteShapeException){
    Shape* rectangle = new Rectangle(5.0, 5.0);
    Shape* rectangle2 = new Rectangle(3.0, 3.0);
    try{
        rectangle->deleteShape(rectangle2);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("You don't have method of deleteShape.", msg);
    }
}

TEST(CaseRectangle, IsDoneOfIteratorEQTrue){
    Shape* rectangle = new Rectangle(5.0, 10.0);
    Iterator* n = rectangle->createIterator();
    
    ASSERT_TRUE(n->isDone());
}

TEST(CaseRectangle, CurrentItemOfIteratorEQThrowException){
    Shape* rectangle = new Rectangle(5.0, 10.0);
    Iterator* n = rectangle->createIterator();
    
    try{
        n->currentItem();
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The currentItem method of Null Iterator is not allowed.", msg);
    }
}