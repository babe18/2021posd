#pragma once
#include "string"

class TwoDimensionalVector {
public:
    TwoDimensionalVector(double x, double y): _x(x),_y(y){}

    double x() const { 
        return _x;
    }

    double y() const { 
        return _y;
    }

    // calculate length of vector
    double length() const {
        // Pythagorean theorem
        return sqrt(pow(_x, 2)+pow(_y, 2));
    }

    double dot(TwoDimensionalVector vec) const { 
        // x1*x2+y1*y2 (dot product)
        return _x*vec.x()+_y*vec.y();
    }

    double cross(TwoDimensionalVector vec) const { 
        //  x1*y2 - y1*x2 (cross product)
        return _x*vec.y()-_y*vec.x();
    }

    TwoDimensionalVector subtract(TwoDimensionalVector vec) const { 
        // x1-x2, y1-y2
        TwoDimensionalVector sub_result(_x-vec.x(), _y-vec.y());
        return sub_result;
    }

    std::string info() const {
        double round_x = round(_x*100.0)/100.0;
        double round_y = round(_y*100.0)/100.0;
        string strx = to_string(_x);
        string stry = to_string(_y);
        return "["+strx.erase(strx.length()-4)+","+stry.erase(stry.length()-4)+"]";
    }

private:
    double _x, _y;
};
