//
//  main.cpp
//  pat_1041
//
//  Created by Michael Hui on 6/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::vector;

int main() {
    map<int, pair<string, int>> data;
    int data_amount = 0;
    int lab_exam_input = 0;
    int pen_exam_input = 0;
    string str_input = "\0";
    cin >> data_amount;
    for(int i = 0; i < data_amount; ++i){
        cin >> str_input >> lab_exam_input >> pen_exam_input;
        data.insert({lab_exam_input, std::make_pair(str_input, pen_exam_input)});
    }
    cin >> data_amount;
    vector <int> required_data;
    for(int i = 0; i < data_amount; ++i){
        cin >> lab_exam_input;
        required_data.push_back(lab_exam_input);
    }
    for(auto const& i: required_data){
        cout << data[i].first << ' ' << data[i].second << endl;
    }
    return 0;
}
