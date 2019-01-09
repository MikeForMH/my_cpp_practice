//
//  main.cpp
//  number_of_sub_palindrome_string_xuetangx_c6_2
//
//  Created by Michael Hui on 8/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
# include <vector>
# include <functional>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::count;
using std::ptr_fun;

bool palindromeString (const string &Input){
    for (int i = 0; i < Input.length()/2; ++i){
        if (Input [i] != Input [Input.length() - i - 1]){
            return false;
        }
    }
    return true;
}

int number_of_palindrome_substring(string &input){
    vector <string> substring_list;
    for(size_t i = 1; i <= input.length() - 1; ++i){
        for(string::iterator j = input.begin(); j != input.end() - i + 1; ++j){
            substring_list.push_back(string(j, j + i));
        }
    }
    int result = 0;
    for(string i: substring_list){
        if(palindromeString(i)){
            ++result;
        }
    }
    return result;
}

int main(){
    string input;
    cin >> input;
    cout << number_of_palindrome_substring(input) << endl;
    return 0;
}
