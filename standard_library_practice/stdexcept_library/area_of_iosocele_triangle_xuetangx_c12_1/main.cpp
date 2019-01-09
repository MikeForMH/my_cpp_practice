//
//  main.cpp
//  area_of_iosocele_triangle_xuetangx_c12_1
//
//  Created by Michael Hui on 8/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>

using namespace std;

/*完善此函数*/
double calArea(double a, double b, double c) throw(invalid_argument){
    if(a <= 0 || b <= 0 || c <= 0){
        throw invalid_argument("The input is illegal");
    }
    if(a + b <= c || b + c <= a || c + a <= b){
        throw invalid_argument("The input is illegal");
    }
    if(a != b && b != c && c != a){
        throw invalid_argument("The input is illegal");
    }
    double s = (a + b + c)/ 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main(){
    double a, b, c;
    cin >> a >> b >> c;
    try{
        double area = calArea(a, b, c);
        cout << fixed << setprecision(2) << area << endl;
    }catch(exception& e){
        cout << e.what() << endl;
    }
}
