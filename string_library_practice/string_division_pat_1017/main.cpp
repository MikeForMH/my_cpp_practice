//
//  main.cpp
//  string_division_pat_1017
//
//  Created by Michael Hui on 30/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;
using std::to_string;

void divide(string &var_1, int &var_2){
    string quotient = "";
    int remainder = 0, temp = 0;
    int carry = 0;
    for(size_t i = 0; i < var_1.length(); ++i){
        temp = (carry * 10 + var_1[i] - '0') / var_2;
        quotient += to_string(temp);
        carry = (carry * 10 + var_1[i] - '0') % var_2;
    }
    remainder = carry;
    if(quotient[0] == '0' && quotient.length() != 1){
        quotient.erase(0, 1);
    }
    cout << quotient << " " << remainder << endl;
    return;
}

int main(){
    string var_1;
    int var_2;
    cin >> var_1 >> var_2;
    divide(var_1, var_2);
    return 0;
}
