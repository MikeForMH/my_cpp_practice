//
//  main.cpp
//  pat_1052
//
//  Created by Michael Hui on 17/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//
//  the given index might be smaller than zero

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;

void initialize_vector(vector<string>& data, int left_bracket, const string& input){
    while(input[left_bracket] != '[' && (left_bracket + 1 < input.length())){
        ++left_bracket;
    }
    if(left_bracket + 1 == input.length()){
        return;
    }
    int right_bracket = left_bracket + 1;
    while(input[right_bracket] != ']'){
        ++right_bracket;
    }
    data.push_back(input.substr(left_bracket + 1, right_bracket - left_bracket - 1));
    if(right_bracket + 1 >= input.length()){
        return;
    }else{
        initialize_vector(data, right_bracket + 1, input);
    }
    return;
}

bool insert_char(string& output, const vector<string>& avail_list, const int& index){
    if(index > avail_list.size() || index <= 0){
        return false;
    }
    output += avail_list[index - 1];
    return true;
}

void output_fail(){
    cout << "Are you kidding me? @\\/@" << endl;
    return;
}

int main() {
    vector<string> hand;
    vector<string> eye;
    vector<string> mouth;
    string line_input = "";
    getline(cin, line_input);
    initialize_vector(hand, 0, line_input);
    getline(cin, line_input);
    initialize_vector(eye, 0, line_input);
    getline(cin, line_input);
    initialize_vector(mouth, 0, line_input);
    int count = 0;
    int num_input = 0;
    vector<vector<int>> require_fig;
    cin >> count;
    for(int i = 0; i < count; ++i){
        vector<int> temp;
        require_fig.push_back(temp);
        for(int j = 0; j < 5; ++j){
            cin >> num_input;
            require_fig[i].push_back(num_input);
        }
    }
    string output_temp = "";
    for(int i = 0; i < count; ++i){
        if(!insert_char(output_temp, hand, require_fig[i][0])){
            output_fail();
            continue;
        }
        output_temp += '(';
        if(!insert_char(output_temp, eye, require_fig[i][1])){
            output_fail();
            continue;
        }
        if(!insert_char(output_temp, mouth, require_fig[i][2])){
            output_fail();
            continue;
        }
        if(!insert_char(output_temp, eye, require_fig[i][3])){
            output_fail();
            continue;
        }
        output_temp += ')';
        if(!insert_char(output_temp, hand, require_fig[i][4])){
            output_fail();
            continue;
        }
        cout << output_temp << endl;
        output_temp = "";
    }
}
