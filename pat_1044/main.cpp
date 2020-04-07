//
//  main.cpp
//  pat_1044
//
//  Created by Michael Hui on 7/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int find_str_index(const vector<string>& data, const string& input){
    for(int i = 0; i < data.size(); ++i){
        if(data[i] == input){
            return i;
        }
    }
    return -1;
}

const vector<string> digit_num = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const vector<string> ten_digit_num = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void earth_to_mars(const string& input){
    int input_num = stoi(input);
    int digit = input_num % 13;
    int ten_digit = input_num / 13;
    if(ten_digit == 0){
        cout << digit_num[digit] << endl;
        return;
    }else if(digit == 0){
        cout << ten_digit_num[ten_digit - 1] << endl;
        return;
    }else{
        cout << ten_digit_num[ten_digit - 1] << ' ' << digit_num[digit] << endl;
        return;
    }
    return;
}

void mars_to_earth(const string& input){
    int result = 0;
    if(input == "tret"){
        cout << 0 << endl;
        return;
    }
    if(input.length() > 3){
        result = find_str_index(digit_num, input.substr(4, 3));
        result += (find_str_index(ten_digit_num, input.substr(0, 3)) + 1)* 13;
    }else{
        if(find_str_index(ten_digit_num, input) != -1){
            cout << (find_str_index(ten_digit_num, input) + 1) * 13 << endl;
            return;
        }else{
            result = find_str_index(digit_num, input);
        }
    }
    cout << result << endl;
    return;
}

int main(){
    int input_count = 0;
    string temp_str = "";
    cin >> input_count;
    cin.ignore();
    for(int i = 0; i < input_count; ++i){
        getline(cin, temp_str);
        if(isdigit(temp_str[0])){
            earth_to_mars(temp_str);
        }else{
            mars_to_earth(temp_str);
        }
    }
    return 0;
}
