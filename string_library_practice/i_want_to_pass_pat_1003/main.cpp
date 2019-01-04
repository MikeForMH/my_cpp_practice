//
//  main.cpp
//  i_want_to_pass_pta_1003
//
//  Created by Michael Hui on 20/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int find_specific_letter(const string &input_string, const char &target_letter){
    for(size_t i = 0; i < input_string.length(); ++i){
        if(input_string[i] == target_letter){
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool is_required_string(const string &input){
    int length = static_cast<int>(input.length());
    int pos_of_p = find_specific_letter(input, 'P');
    if(pos_of_p == -1){
        return false;
    }
    int a_count_pre_p = 0;
    for(int i = 0; i < pos_of_p; ++i){
        if(input[i] != 'A'){
            return false;
        }
        ++a_count_pre_p;
    }
    int pos_of_t = find_specific_letter(input, 'T');
    if(pos_of_t == -1 || pos_of_t < pos_of_p){
        return false;
    }
    int a_count_post_t = 0;
    for(int i = pos_of_t + 1; i < length; ++i){
        if(input[i] != 'A'){
            return false;
        }
        ++a_count_post_t;
    }
    int a_count_in_mid = 0;
    for(int i = pos_of_p + 1; i < pos_of_t; ++i){
        if(input[i] != 'A'){
            return false;
        }
        ++a_count_in_mid;
    }
    if(a_count_pre_p * a_count_in_mid == a_count_post_t && a_count_in_mid != 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    string input_string;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> input_string;
        if(is_required_string(input_string)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
