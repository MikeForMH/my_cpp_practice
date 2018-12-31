//
//  main.cpp
//  parameter_and_area_of_circle_xuetangx_c8_2
//
//  Created by Michael Hui on 31/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

#include <iostream>
using namespace std;

const double pi = 3.14;

class Shape{
public:
    Shape(){}
    ~Shape(){}
    virtual double getArea() = 0;
    virtual double getPerim() = 0;
};

class Circle: public Shape{
public:
    Circle(double rad):radius(rad){}
    ~Circle(){}
    
    /*补充这两个函数*/
    double getArea();
    double getPerim();
private:
    double radius;
};

double Circle::getArea(){
    return pi * radius * radius;
}

double Circle::getPerim(){
    return 2 * radius * pi;
}

int main() {
    double radius;
    cin >> radius;
    Circle c(radius);
    cout << c.getArea() << " " << c.getPerim() << endl;
}
