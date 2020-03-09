//
//  main.cpp
//  circle_area
//
//  Created by Michael Hui on 10/3/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*

long double find_ellipse_area(double precision, double axis_a, double axis_b){
    double magnitude = 0.2
    double epsilon = precision * 10;
    int array_size = int((axis_a / magnitude + 1) * (axis_b / magnitude + 1));
    int
}

 */

bool comparator(double x, double y, double axis_a, double axis_b){
    return ((x * x)/(axis_a * axis_a) + (y * y)/(axis_b * axis_b)) <= 1;
}

long double find_ellipse_area(double precision, double axis_a, double axis_b){
    int count = 0;
    for(double i = precision / 2; i <= axis_b + precision; i += precision){
        for(double j = precision / 2; j <= axis_a; j += precision){
            if(comparator(i, j, axis_a, axis_b)){
            ++count;
            }
        }
    }
    return 4 * count * precision * precision;
    
}

int main(){
    double precision_input = 0;
    double axis_a_input = 0;
    double axis_b_input = 0;
    cout << "Please enter the precision:";
    cin >> precision_input;
    cout << endl << "Please enter the 'a' and 'b' of the ellipse:";
    cin >> axis_a_input >> axis_b_input;
    cout << endl;
    cout << find_ellipse_area(precision_input, axis_a_input, axis_b_input) << endl;
    return 0;
}
