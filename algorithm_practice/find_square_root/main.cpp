//
//  main.cpp
//  find_square_root
//
//  Created by Michael Hui on 13/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//
// -------------------------------THIS IS USED FOR ROUND DOWN.-------------------------------------------

# include <iostream>
# include <cmath>
# include <iomanip>
using std::cin;
using std::cout;
using std::endl;

double sqrt(const int &N){
    if (N == 1){
        return 1;
    }
    const double EPSILON = 1e-6;
    double upper_boundary = N, lower_boundary = 0, mid_pt = (upper_boundary + lower_boundary) / 2;
    while (fabs(mid_pt * mid_pt - N) > EPSILON){
        if (mid_pt * mid_pt > N){
            upper_boundary = mid_pt;
            mid_pt = (upper_boundary + lower_boundary) / 2;
        }
        else {
            lower_boundary = mid_pt;
            mid_pt = (upper_boundary + lower_boundary) / 2;
        }
    }
    return mid_pt;
}

int main(){
    int N;
    while (cin >> N){
        cout << floor(sqrt(N)) << endl;
    }
    return 0;
}
