//
//  main.cpp
//  dynamic_cast_practice_xuetangx_c8_3
//
//  Created by Michael Hui on 31/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

class Shape{
public:
    Shape() {}
    virtual ~Shape() {}
};

class Triangle: public Shape{
public:
    Triangle() {}
    ~Triangle() {}
};

class Rectangle: public Shape {
public:
    Rectangle() {}
    ~Rectangle() {}
};

/*用dynamic_cast类型转换操作符完成该函数*/
int getVertexCount(Shape * b){
    Rectangle *rectangle = dynamic_cast<Rectangle*>(b);
    if(rectangle != NULL){
        return 4;
    }
    Triangle *triangle = dynamic_cast<Triangle*>(b);
    if(triangle != NULL){
        return 3;
    }
    Shape *shape = dynamic_cast<Shape*>(b);
    if(shape != NULL){
        return 0;
    }
    return -1;
}

int main() {
    Shape s;
    cout << getVertexCount(&s) << endl;
    Triangle t;
    cout << getVertexCount(&t) << endl;
    Rectangle r;
    cout << getVertexCount(&r) << endl;
}
