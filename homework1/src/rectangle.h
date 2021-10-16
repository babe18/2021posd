#include <cmath>
#include "shape.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Rectangle: public Shape{
public:
  Rectangle(double width, double height):_width(width), _height(height)  {
    if(_width<=0 || _height<=0){
      run=false;
      throw string ("This is not a rectangle!");
    }
    strwidth = to_string(width);
    strheight = to_string(height);
    recinfo ="Rectangle ("+strwidth.erase(strwidth.length()-4) +" "+strheight.erase(strheight.length()-4) +")";
  }

  double area() const {
    if(run) return _width * _height;
    else return -1;
  }

  double perimeter() const {
    if(run) return (2.0*(_width + _height));
    else return -1;
  }

  std::string info() const {
      return recinfo;
  }

private:
  double _width, _height;
  string recinfo,strwidth,strheight;
  bool run=true;
};
