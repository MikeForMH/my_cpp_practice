//
//  main.cpp
//  output_float_xuetangx_c11_1
//
//  Created by Michael Hui on 7/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <iomanip>
# include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::trunc;
using std::pow;
using std::setfill;
using std::setw;

int main(){
    int left_width, right_width;
    double input;
    cout << setfill('0');
    while(cin >> left_width >> right_width >> input){
        if(left_width == 0 && right_width == 0){
            cout << "0" << endl;
            continue;
        }
        int point_count = 1;
        if(right_width == 0){
            point_count = 0;
        }
        input = trunc(input * pow(10, right_width));
        input /= pow(10, right_width);
        cout << fixed << setprecision(right_width) << setw(left_width + right_width + point_count);
        cout << input << endl;
    }
    return 0;
}
