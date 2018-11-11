//
//  main.cpp
//  roman_to_decimal
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

int roman_to_decimal(const string &roman_numerals){
    int result = 0;
    int numerals_length = static_cast <int> (roman_numerals.length());
    string input_roman_numerals = roman_numerals;
    string roman_numerals_list[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int decimal_number_list[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int length_to_be_check;
    for(int i = 12; i >= 0 && numerals_length > 0; --i){
        length_to_be_check = static_cast <int> (roman_numerals_list[i].length());
        if(numerals_length < length_to_be_check){
            continue;
        }
        for (;numerals_length >= length_to_be_check;){
            string temp_string = "";
            for(int k = length_to_be_check, n = 1; k > 0; --k, ++n){
                temp_string = input_roman_numerals[numerals_length - n] + temp_string;
            }
            if (temp_string == roman_numerals_list[i]){
                result += decimal_number_list[i];
                for(int m = length_to_be_check; m > 0; --m){
                    input_roman_numerals.pop_back();
                    --numerals_length;
                }
            }
            else {
                break;
            }
        }
    }
    return result;
}

int main(){
    string roman_numerals;
    cin >> roman_numerals;
    cout << roman_to_decimal(roman_numerals) << endl;
    return 0;
}
