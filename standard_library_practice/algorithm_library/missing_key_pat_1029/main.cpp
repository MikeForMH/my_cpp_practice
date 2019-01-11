//
//  main.cpp
//  missing_key_pat_1029
//
//  Created by Michael Hui on 12/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
# include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::toupper;
using std::unique;
using std::find;

string& remove_duplicated_char(string &input){
    string result;
    for(size_t i = 0; i < input.length(); ++i){
        if(find(result.begin(), result.end(), input[i]) == result.end()){
            result.push_back(input[i]);
        }
    }
    input = result;
    return input;
}

void find_missing_key(string input_key, string receiving_key){
    for(auto &var: input_key){
        var = toupper(var);
    }
    for(auto &var: receiving_key){
        var = toupper(var);
    }
    remove_duplicated_char(input_key);
    remove_duplicated_char(receiving_key);
    for(auto &var: input_key){
        auto temp = find(receiving_key.begin(), receiving_key.end(), var);
        if(temp == receiving_key.end()){
            cout << var;
        }
    }
    cout << endl;
    return;
}

int main(){
    string input_key, receiving_key;
    cin >> input_key >> receiving_key;
    find_missing_key(input_key, receiving_key);
    return 0;
}
