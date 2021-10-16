#include "shape.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <cmath>
#include "two_dimensional_vector.h"

using namespace std;

class Triangle: public Shape{
public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2):_vec1(vec1),_vec2(vec2){
      if(_vec1.cross(_vec2)==0){
          run=false;
          throw string ("This is not a triangle!");
      }
      TwoDimensionalVector _vec3 = _vec1.subtract(_vec2);
      side3 = sqrt( pow(_vec3.x(),2) + pow(_vec3.y(),2));
      triperimeter = _vec1.length()+_vec2.length()+side3;
      s=triperimeter/2;
      triarea = sqrt( s * (s-_vec1.length()) * (s-_vec2.length()) * (s-side3));
    }

    double perimeter() const {
      if(run) return triperimeter;
      else return -1;
    }

    double area() const {
      if(run) return triarea;
      else return -1;
    }

    std::string info() const {
        string x1 = to_string(_vec1.x());
        string y1 = to_string(_vec1.y());
        string x2 = to_string(_vec2.x());
        string y2 = to_string(_vec2.y());
        string ans ="Triangle ([" + x1.erase(x1.length()-4) + "," + y1.erase(y1.length()-4) + "] [" + x2.erase(x2.length()-4) + "," + y2.erase(y2.length()-4) + "])";
        return ans;
    }

  private:
    TwoDimensionalVector _vec1, _vec2;
    double triperimeter, triarea, side3 ,s;
    bool run=true;
};