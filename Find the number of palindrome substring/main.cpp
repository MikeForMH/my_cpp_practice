//
//  main.cpp
//  Find the number of palindrome substring
//
//  Created by Michael Hui on 4/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <cmath>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void palindromeString (const string &Input){
    for (int i = 0; i < Input.length()/2; ++i){
        if (Input [i] != Input [Input.length() - i - 1]){
            //cout << "No." << endl;
            return;
        }
    }
    //cout << "Yes." << endl;
    return;
}

int find_number_of_palindrome_substring (string Input){
    int required_substring_number = 0, Input_length = static_cast <int> (Input.length());
    for (int i = 0; i < Input_length; ++i){
        for (int j = 1; j < )
            }
}

int main (){
    string Input;
    cout << find_number_of_palindrome_substring(Input) << endl;
    return 0;
}
