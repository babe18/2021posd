#include <iostream>
#include "../src/circle.h"
using namespace std;

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
