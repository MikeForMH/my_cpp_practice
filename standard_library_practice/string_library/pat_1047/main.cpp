//
//  main.cpp
//  pat_1047
//
//  Created by Michael Hui on 10/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main() {
    map<string, int> data;
    string str_temp = "";
    string win_team = "";
    int int_temp = 0;
    int input_count = 0;
    int win_score = 0;
    cin >> input_count;
    for(int i = 0; i < input_count; ++i){
        cin >> str_temp >> int_temp;
        str_temp = str_temp.erase(str_temp.find('-'));
        auto iter = data.find(str_temp);
        if(iter == data.end()){
            data.insert({str_temp, int_temp});
        }else{
            iter->second += int_temp;
        }
    }
    for(auto const &i: data){
        if(i.second > win_score){
            win_score = i.second;
            win_team = i.first;
        }
    }
    cout << win_team << ' ' <<win_score << endl;
    return 0;
}
