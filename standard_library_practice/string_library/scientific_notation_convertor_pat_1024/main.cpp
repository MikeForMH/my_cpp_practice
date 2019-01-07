//
//  main.cpp
//  scientific_notation_convertor_pat_1024
//
//  Created by Michael Hui on 7/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;

string scientific_to_decimal(string &input){
    bool is_positive;
    if(input[0] == '+'){
        is_positive = true;
    }
    else{
        is_positive = false;
    }
    input.erase(0, 1);
    int decimal_point = -1;
    string decimal_part;
    for(int i = 0; ; i++){
        if(input[i] == 'E'){
            if(decimal_point == -1){
                decimal_point = i;
            }
            input.erase(0, i + 1);
            break;
        }
        else if(input[i] == '.'){
            decimal_point = i;
            continue;
        }
        decimal_part.push_back(input[i]);
    }
    int index_part = stoi(input);
    decimal_point += index_part;
    if(decimal_point >= int(decimal_part.length())){
        decimal_part.append(decimal_point - decimal_part.length(), '0');
        while(decimal_part[0] == '0'){
            decimal_part.erase(0, 1);
        }
        if(decimal_part.empty()){
            decimal_part = "0";
        }
    }
    else{
        if(1 - decimal_point > 0){
            decimal_part.insert(0, 1 - decimal_point, '0');
            decimal_part.insert(1, 1, '.');
        }
        else{
            decimal_part.insert(decimal_point, 1, '.');
            while(decimal_part[0] == '0'){
                decimal_part.erase(0, 1);
            }
            if(decimal_part.empty()){
                decimal_part = "0";
            }
        }
    }
    if(!is_positive){
        decimal_part.insert(0, 1, '-');
    }
    return decimal_part;
}

int main(){
    string scientific_notation_input;
    cin >> scientific_notation_input;
    cout << scientific_to_decimal(scientific_notation_input) << endl;
    return 0;
}
