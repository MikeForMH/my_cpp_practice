//
//  main.cpp
//  Bisection method (For linear)
//
//  Created by Michael Hui on 4/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

#include <cstdio>
#include <cmath>
#define EPSILON 1e-7

double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);
int main() {
    int p;
    int q;
    scanf("%d %d", &p, &q);
    printf("%.4lf\n", bisection(p, q, f));
    return 0;
}

double bisection(int p, int q, double (*func)(int, int, double)) {
    double left_x = -20, right_x = 20;
    double left_result = (*func)(p, q, left_x);
    double right_result = (*func)(p, q, right_x);
    double mid_x = (left_x + right_x) / 2;
    ///*
    
    for (;fabs((*func)(p, q, mid_x)) > EPSILON;){
        if ((*func)(p, q, mid_x) > 0){
            if (left_result < 0){
                right_x = mid_x;
                right_result = (*func)(p, q, mid_x);
                mid_x = (left_x + right_x) / 2;
            }
            else { // left_result > 0, right_ result < 0
                left_x = mid_x;
                left_result = (*func)(p, q, mid_x);
                mid_x = (left_x + right_x) / 2;
            }
        }
        else { //(*func)(p, q, mid_pt) <= 0
            if (left_result > 0){
                right_x = mid_x;
                right_result = (*func)(p, q, mid_x);
                mid_x = (left_x + right_x) / 2;
            }
            else { //left_result >= 0, right_result < 0
                left_x = mid_x;
                left_result = (*func)(p, q, mid_x);
                mid_x = (left_x + right_x) / 2;
            }
        }
    }
    return mid_x;
    
    //*/
    
    //return (*func)(p, q, -0.1636);
}

double f(int p, int q, double x) {
    return p * x + q;
}
