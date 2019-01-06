//
//  main.cpp
//  large_integer_comparing_pat_1011
//
//  Created by Michael Hui on 23/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::swap;
using std::stoi;
using std::to_string;

string subtract_by_string(string &positive, string &negative){
    string result, temp;
    int pos_digit, neg_digit, carry = 0;
    while(!positive.empty() || !negative.empty()){
        pos_digit = 0;
        neg_digit = 0;
        if(!positive.empty()){
            temp = positive.back();
            pos_digit = stoi(temp);
            positive.pop_back();
        }
        if(!negative.empty()){
            temp = negative.back();
            neg_digit = -stoi(temp);
            negative.pop_back();
        }
        int digit_sum = pos_digit + neg_digit + carry;
        if(digit_sum >= 0){
            result = to_string(digit_sum) + result;
            carry = 0;
        }
        else{
            result = to_string(10 + digit_sum) + result;
            carry = -1;
        }
    }
    while(result[0] == '0'){
        result.erase(0, 1);
    }
    return result;
}

int compare_absolute_avlue(string &var_1, string &var_2){
    if(var_1.length() > var_2.length()){
        return 1;
    }
    else if(var_2.length() > var_1.length()){
        return 2;
    }
    for(size_t i = 0; i < var_1.length(); ++i){
        if(var_1[i] == var_2[i]){
            continue;
        }
        else if(var_1[i] > var_2[i]){
            return 1;
        }
        else{
            return 2;
        }
    }
    return 3;
}

string positive_addition(string &var_1, string &var_2){
    string result, temp;
    int carry = 0, digit_1, digit_2;
    while(!var_1.empty() || !var_2.empty()){
        digit_1 = 0;
        digit_2 = 0;
        if(!var_1.empty()){
            temp = var_1.back();
            digit_1 = stoi(temp);
            var_1.pop_back();
        }
        if(!var_2.empty()){
            temp = var_2.back();
            digit_2 = stoi(temp);
            var_2.pop_back();
        }
        result = to_string((digit_1 + digit_2 + carry) % 10) + result;
        carry = (digit_1 + digit_2 + carry) / 10;
    }
    if(carry != 0){
        result = to_string(carry) + result;
    }
    return result;
}

string add_by_string(string &var_1, string &var_2){
    if(isdigit(var_1[0]) && isdigit(var_2[0])){
        return positive_addition(var_1, var_2);
    }
    else if (var_1[0] == '-' && var_2[0] == '-'){
        string result = positive_addition(var_1.erase(0, 1), var_2.erase(0, 1));
        result = "-" + result;
        return result;
    }
    else if(var_1[0] == '-'){
        string result;
        switch(compare_absolute_avlue(var_1.erase(0, 1), var_2)){
            case 1:
                result = "-" + subtract_by_string(var_1, var_2);
                break;
            case 2:
                result = subtract_by_string(var_2, var_1);
                break;
            case 3:
                result = "0";
                break;
        }
        return result;
    }
    else{
        string result;
        switch(compare_absolute_avlue(var_1, var_2.erase(0, 1))){
            case 1:
                result = subtract_by_string(var_1, var_2);
                break;
            case 2:
                result = "-" + subtract_by_string(var_2, var_1);
                break;
            case 3:
                result = "0";
                break;
        }
        return result;
    }
}

bool a_is_largr_than_b(string &a, string &b){
    if(isdigit(a[0]) && isdigit(b[0])){
        if(compare_absolute_avlue(a, b) == 1){
            return true;
        }
        else{
            return false;
        }
    }
    else if(a[0] == '-' && b[0] == '-'){
        if(compare_absolute_avlue(a.erase(0, 1), b.erase(0, 1)) == 2){
            return true;
        }
        else{
            return false;
        }
    }
    else if(a[0] == '-'){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    int t;
    string a, b, c, a_plus_b;
    cin >> t;
    for(int i = 1; i <= t; ++ i){
        cin >> a >> b >> c;
        a_plus_b = add_by_string(a, b);
        if(a_is_largr_than_b(a_plus_b, c)){
            cout << "Case #" << i << ": true" << endl;
        }
        else{
            cout << "Case #" << i << ": false" << endl;
        }
    }
    return 0;
}
