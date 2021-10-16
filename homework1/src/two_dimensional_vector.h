#ifndef TWO_DIMENSIONAL_VECTOR_H
#define TWO_DIMENSIONAL_VECTOR_H
#include <string>
#include <cmath>
using namespace std;

class TwoDimensionalVector {
public:
    TwoDimensionalVector(double x, double y):_x(x),_y(y){}

    double x() const {
        return _x;
	}

	 double y() const {
       return _y;
	}

    double length() const {
        return sqrt(_x*_x+_y*_y);
    }

    double dot(TwoDimensionalVector vec) const {
        return vec.x()*_x+vec.y()*_y;
    }

    double cross(TwoDimensionalVector vec) const {
        return _x*vec.y() - _y*vec.x();
    }

    TwoDimensionalVector subtract(TwoDimensionalVector vec) const {
        double new_x(_x-vec.x()), new_y(_y-vec.y());
        TwoDimensionalVector res(new_x, new_y);
        return res;
    }

    std::string info() const {
        string strx = to_string(_x);
        string stry = to_string(_y);
        return "["+strx.erase(strx.length()-4)+","+stry.erase(stry.length()-4)+"]";
    }

private:
    double _x,_y;
};
#endif
