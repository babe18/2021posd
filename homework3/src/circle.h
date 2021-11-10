#pragma once
#include "shape.h"
#include <string>
#include <string.h>
#include "iterator/iterator.h"
#include "iterator/null_iterator.h"
#include <cmath>
using namespace std;

class Circle : public Shape {
public:
    Circle(double radius):_radius(radius){
        if(_radius<=0){
            run=false;
            throw string ("This is not a circle!");
        }
        double round_radius = round(_radius*100.0)/100.0;
        str_radius = to_string(round_radius);
        cirinfo="Circle ("+ str_radius.erase(str_radius.length()-4)+ ")";
    }

    double area() const override { 
        return _radius*_radius*M_PI;
    }

    double perimeter() const override { 
        return _radius*2*M_PI;
    }

    std::string info() const override { 
        return cirinfo;
    }

    Iterator* createIterator() override {
        return new NullIterator();
    }
private:
    double _radius;
    string cirinfo="", str_radius="";
    bool run= true;
};