//
//  main.cpp
//  a_plus_b_in_base_n
//
//  Created by Michael Hui on 4/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;
using std::to_string;
using std::vector;

int remainder_of_a_divide_b(string &dividend, int &divisor){
    if(divisor == 0){
        cout << "don't divide by 0." << endl;
        return -1;
    }
    string quotient = {};
    int carry = 0, temp;
    for(size_t i = 0; i < dividend.length(); ++i){
        carry *= 10;
        temp = dividend[i] - '0' + carry;
        if(temp >= divisor){
            quotient = quotient + to_string(temp / divisor);
            carry = temp % divisor;
        }
        else{
            quotient.push_back('0');
            carry = temp;
        }
    }
    if(quotient[0] == '0'){
        quotient.erase(0, 1);
    }
    if(quotient.empty()){
        quotient.push_back('0');
    }
    dividend = quotient;
    return carry;
}

string a_plus_b_in_n_base(string &var_1, string &var_2, int &base){
    string result_in_10 = {}, result_in_base;
    int carry = 0, temp_1, temp_2;
    while(!var_1.empty() || !var_2.empty()){
        temp_1 = 0; temp_2 = 0;
        if(!var_1.empty()){
            temp_1 = var_1.back() - '0';
            var_1.pop_back();
        }
        if(!var_2.empty()){
            temp_2 = var_2.back() - '0';
            var_2.pop_back();
        }
        result_in_10 = to_string((temp_1 + temp_2 + carry) % 10) + result_in_10;
        carry = (temp_1 + temp_2 + carry) / 10;
    }
    while(carry != 0){
        result_in_10 = to_string(carry % 10) + result_in_10;
        carry /= 10;
    }
    while(result_in_10 != "0"){
        result_in_base = to_string(remainder_of_a_divide_b(result_in_10, base)) + result_in_base;
    }
    if(result_in_base.empty()){
        result_in_base.push_back('0');
    }
    return result_in_base;
}

int main(){
    string var_1, var_2;
    int base;
    cin >> var_1 >> var_2 >> base;
    cout << a_plus_b_in_n_base(var_1, var_2, base) << endl;
    return 0;
}
