#pragma once
#include "string"

class Iterator;

class Shape {
public:
    virtual ~Shape() {};

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual std::string info() const = 0;

    virtual Iterator* createIterator() = 0;

    virtual void addShape(Shape* shape) { 
        throw std::string("You don't have method of addShape.");
    }

    virtual void deleteShape(Shape* shape) { 
        throw std::string("You don't have method of deleteShape.");
    }
};