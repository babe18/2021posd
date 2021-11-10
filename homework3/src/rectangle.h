#pragma once
#include "shape.h"
#include "string"
#include "iterator/iterator.h"
#include "iterator/null_iterator.h"
#include <cmath>
using namespace std;

class Rectangle : public Shape {
public: 
    Rectangle(double width, double height):_width(width), _height(height)  {
        if(_width<=0 || _height<=0){
        run=false;
        throw string ("This is not a rectangle!");
        }
        double round_width = round(_width*100.0)/100.0;
        double round_height = round(_height*100.0)/100.0;
        strwidth = to_string(round_width);
        strheight = to_string(round_height);
        recinfo ="Rectangle ("+strwidth.erase(strwidth.length()-4) +" "+strheight.erase(strheight.length()-4) +")";
    }

    // the calculation is length * width
    double area() const override {
        return _height*_width;
    }

    // the calculation is 2*(length+width)
    double perimeter() const override { 
        return 2*(_height+_width);
    }
    
    // show the information of rectangle with decimal point of two
    std::string info() const override { 
        return recinfo;
    }

    Iterator* createIterator() override { 
        return new NullIterator();
    }

private:
    double _width, _height;
    string recinfo,strwidth,strheight;
    bool run=true;
};
