//
//  main.cpp
//  categorise_number_pat_1012
//
//  Created by Michael Hui on 25/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;

int main(){
    int n, input_number;
    int a_1 =0, a_2 = 0, a_3 = 0, a_5 = 0;
    double a_4 = 0; int a_4_count = 0;
    bool a_2_sign = true, a_2_flag = false;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> input_number;
        if(input_number % 10 == 0){
            a_1 += input_number;
        }
        if(input_number % 5 == 1){
            a_2_flag = true;
            if(a_2_sign){
                a_2 += input_number;
                a_2_sign = false;
            }
            else{
                a_2 -= input_number;
                a_2_sign = true;
            }
        }
        if(input_number % 5 == 2){
            ++a_3;
        }
        if(input_number % 5 == 3){
            a_4 += input_number;
            ++a_4_count;
        }
        if(input_number % 5 == 4){
            if(input_number > a_5){
                a_5 = input_number;
            }
        }
    }
    if(a_1 != 0){
        cout << a_1 << " ";
    }
    else{
        cout << "N ";
    }
    if(a_2_flag){
        cout << a_2 << " ";
    }
    else{
        cout << "N ";
    }
    if(a_3 != 0){
        cout << a_3 << " ";
    }
    else{
        cout << "N ";
    }
    if(a_4_count != 0){
        cout << fixed << setprecision(1) << a_4 / a_4_count << " ";
    }
    else{
        cout << "N ";
    }
    if(a_5 != 0){
        cout << a_5 << endl;
    }
    else{
        cout << "N" << endl;
    }
    return 0;
}
