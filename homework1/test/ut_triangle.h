#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"

TEST(Triangle, TestTriangle) {
  TwoDimensionalVector t1(3, 0);
  TwoDimensionalVector t2(0, 4);
  Triangle triangle(t1,t2);
  ASSERT_EQ(6.0, triangle.area());
  ASSERT_EQ(12, triangle.perimeter());
  ASSERT_EQ("Triangle ([3.00,0.00] [0.00,4.00])", triangle.info());
}


  TEST(Triangle, TestTrianglefail) {
    TwoDimensionalVector t1(1, 1);
    TwoDimensionalVector t2(2, 2);
    try{
            Triangle triangle4(t1,t2);
             FAIL(); // you want fail but success means this test fail.
          }catch(std::string e){
            EXPECT_EQ(std::string("This is not a triangle!"), e);
          }
    }
