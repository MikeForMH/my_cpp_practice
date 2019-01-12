//
//  main.cpp
//  validity_of_id_pat_1031
//
//  Created by Michael Hui on 12/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
# include <vector>
# include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::isdigit;

int id_digit_weighting[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char check_digit_list[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool is_valid_id(string &input){
    for(int i = 0; i < 17; ++i){
        if(!isdigit(input[i])){
            return false;
        }
    }
    int weight_sum = 0;
    for(int i = 0; i < 17; ++i){
        weight_sum += (input[i] - '0') * id_digit_weighting[i];
    }
    int check_digit_Z = weight_sum % 11;
    if(input[17] == check_digit_list[check_digit_Z]){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n;
    string input;
    vector <string> invalid_id_list;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> input;
        if(!is_valid_id(input)){
            invalid_id_list.push_back(input);
        }
    }
    if(invalid_id_list.empty()){
        cout << "All passed" << endl;
    }else{
        for(string &var: invalid_id_list){
            cout << var << endl;
        }
    }
    return 0;
}
