//
//  main.cpp
//  pat_1051
//
//  Created by Michael Hui on 16/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::sin;
using std::cos;
using std::fixed;
using std::setprecision;

int main() {
    double r1 = 0;
    double p1 = 0;
    double r2 = 0;
    double p2 = 0;
    double a = 0;
    double b = 0;
    cin >> r1 >> p1 >> r2 >> p2;
    a = r1 * cos(p1) * r2 * cos(p2) - r1 * sin(p1) * r2 * sin(p2);
    b = r1 * cos(p1) * r2 * sin(p2) + r1 * sin(p1) * r2 * cos(p2);
    if(a > -0.005 && a < 0){
        a = 0;
    }
    cout << fixed << setprecision(2) << a;
    if(b > -0.005 && b < 0){
        cout << "+0.00i";
    }else if(b > 0){
        cout << '+' << b << 'i';
    }else{
        cout << b << 'i';
    }
    cout << endl;
    return 0;
}
