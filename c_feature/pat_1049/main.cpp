//
//  main.cpp
//  pat_1049
//
//  Created by Michael Hui on 11/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main(){
    int input_count = 0;
    double temp = 0;
    double result = 0;
    double data[100000] = {0};
    cin >> input_count;
    for(int i = 0; i < input_count; ++i){
        scanf("%lf", &temp);
        data[i] = temp;
    }
    for(int i = 0; i < input_count; ++i){
        result += data[i] * (i + 1) * (input_count - i);
    }
    cout << std::fixed << std::setprecision(2) << result << endl;
    return 0;
}
