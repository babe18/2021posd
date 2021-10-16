#include <iostream>
#include "../src/two_dimensional_vector.h"
using namespace std;

TEST(TwoDimensionalVector, TestTwoDimensionalVector){
  TwoDimensionalVector t1(3, 4), t2(6, 5);
  ASSERT_EQ(3, t1.x());
  ASSERT_EQ(4, t1.y());
  ASSERT_EQ(5, t1.length());
  ASSERT_EQ(38, t1.dot(t2));
  ASSERT_EQ(-9, t1.cross(t2));
  ASSERT_EQ(-3, t1.subtract(t2).x());
  ASSERT_EQ(-1, t1.subtract(t2).y());
  ASSERT_EQ("[3.00,4.00]", t1.info());
}