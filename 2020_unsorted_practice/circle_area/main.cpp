//
//  main.cpp
//  circle_area
//
//  Created by Michael Hui on 10/3/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;

double precision = 0;
double axis_a = 0;
double axis_b = 0;

bool comparator(double x, double y){
    return ((x * x)/(axis_a * axis_a) + (y * y)/(axis_b * axis_b)) <= 1;
}

double bi_search_ellipse(double &upper, double &lower, double &x){
    double mid = (upper + lower) / 2;
    if(upper - lower < precision){
        return mid;
    }
    if(comparator(x, mid)){ // fall inside the ellipse
        return bi_search_ellipse(upper, mid, x);
    }else{
        return bi_search_ellipse(mid, lower, x); // fall outside the ellipse
    }
}

double solve_y(double &x){
    return axis_b * sqrt(pow(axis_a, 2) - pow(axis_b, 2)) / axis_a;
}

double f_ellipse(double &x){
    return (axis_a * sqrt(pow(axis_b, 2) - pow(x, 2)))/axis_b;
}

double f_prime_ellipse(double &x){
    return (-1) * axis_a * x / (axis_b * sqrt(pow(axis_b, 2) - pow(x, 2)));
}

double newton_method_recur(double &precision, double &x){
    double new_x = x - f_ellipse(x) / f_prime_ellipse(x);
    if(abs(x - new_x) < precision){
        return new_x;
    }
    return newton_method_recur(precision, new_x);
}

double ellipse_area_with_newton_method(double &precision){
    double accumulator = 0;
    for(double i = precision / 2; i <= axis_a + precision; i += precision){
        accumulator += solve_y(i);
    }
    return 4 * accumulator * precision;
}

long double find_ellipse_area(double precision, double axis_a, double axis_b){
    double zero = 0;
    double accumulator = 0;
    for(double i = precision / 2; i <= axis_a + precision; i += precision){
        accumulator += bi_search_ellipse(axis_b, zero, i);
    }
    return 4 * accumulator * precision;
}

int main(){
    cout << "Please enter the precision: ";
    cin >> precision;
    cout << "Please enter the 'a' and 'b' of the ellipse: ";
    cin >> axis_a >> axis_b;
    auto t1 = std::chrono::high_resolution_clock::now();
    cout.precision(15);
    cout << "Area: " << fixed << ellipse_area_with_newton_method(precision) << endl;
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    cout << "time use: " << duration / 1000 << " ms" << endl;
    return 0;
}
