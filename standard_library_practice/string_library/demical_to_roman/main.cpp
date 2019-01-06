//
//  main.cpp
//  testing_target
//
//  Created by Michael Hui on 11/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

string decimal_to_roman(const int &decimal_number){
    int input_number = decimal_number;
    string result;
    string roman_numerals_list[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int decimal_number_list[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    for(int i = 0; i < 13; ++i){
        if (input_number < decimal_number_list[i]){
            continue;
        }
        while (input_number >= decimal_number_list[i] && input_number > 0){
            input_number -= decimal_number_list[i];
            result += roman_numerals_list[i];
        }
    }
    return result;
}

int main(){
    int decimal_number;
    cin >> decimal_number;
    cout << decimal_to_roman(decimal_number) << endl;
    return 0;
}

