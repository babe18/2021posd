#include <cmath>
#include "shape.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Circle : public Shape {
public:
    Circle(double radius):_radius(radius){
        if(_radius<=0){
            run=false;
            throw string ("This is not a circle!");
        }
        str_radius = to_string(_radius);
        cirinfo="Circle ("+ str_radius.erase(str_radius.length()-4)+ ")";
    }

    double area() const {
        if(run) return M_PI*pow(_radius,2);
        else return -1;
    }

    double perimeter() const {
         if(run) return M_PI*_radius*2;
         else return -1;
    }

    string info() const {
        return cirinfo;
    }
private:
    double _radius;
    string cirinfo="", str_radius="";
    bool run= true;
};
