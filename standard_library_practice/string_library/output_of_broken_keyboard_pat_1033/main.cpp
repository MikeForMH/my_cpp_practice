//
//  main.cpp
//  output_of_broken_keyboard_pat_1033
//
//  Created by Michael Hui on 13/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//
//  there could be no broken key, thus function getline() is needed.

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::remove;
using std::vector;
using std::isalpha;
using std::tolower;
using std::find;
using std::isupper;


void output_with_broken_key(string &broken_key, string &original_input){
    vector<char> lower_case;
    string::iterator iter = find(broken_key.begin(), broken_key.end(), '+');
    if(iter != broken_key.end()){
        for(size_t i = 0; i < original_input.length(); ++i){
            if(isupper(original_input[i])){
                original_input.erase(i, 1);
                --i;
            }
        }
        broken_key.erase(iter);
    }
    for(size_t i = 0; i < broken_key.length(); ++i){
        if(isalpha(broken_key[i])){
            lower_case.push_back(tolower(broken_key[i]));
        }
        original_input.erase(remove(original_input.begin(), original_input.end(), broken_key[i]), original_input.end());
    }
    for(char var: lower_case){
        original_input.erase(remove(original_input.begin(), original_input.end(), var), original_input.end());
    }
    if(original_input.empty()){
        cout << endl;
    }else{
        cout << original_input << endl;
    }
    
}

int main(){
    string broken_key, original_input;
    getline(cin, broken_key);
    getline(cin, original_input);
    
    if(!broken_key.empty()){
        output_with_broken_key(broken_key, original_input);
    }else{
        cout << original_input << endl;
    }
    return 0;
}
