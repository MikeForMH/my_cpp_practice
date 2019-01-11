//
//  main.cpp
//  get_runtime_pat_1026
//
//  Created by Michael Hui on 11/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//
//  my heart is soothed :)

# include <iostream>
# include <cmath>
# include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::right;
using std::setw;
# define NEW_CLK_TCK 100

void get_programme_runtime(double &c1, double &c2){
    int duration = floor((c2 - c1) / 100 + 0.5);
    int second = duration % 60;
    duration /= 60;
    int minute = duration % 60;
    duration /= 60;
    cout << setfill('0') << right << setw(2) << duration << ":" << setw(2) << minute << ":";
    cout << setw(2) << second;
    return;
}

int main(){
    double c1, c2;
    cin >> c1 >> c2;
    get_programme_runtime(c1, c2);
    return 0;
}
