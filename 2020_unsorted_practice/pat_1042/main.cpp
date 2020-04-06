//
//  main.cpp
//  pat_1042
//
//  Created by Michael Hui on 6/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <cctype>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::set;
using std::function;
using std::vector;
using std::sort;

typedef function<bool(pair<char, int>, pair<char, int>)> Comparator;

int main() {
    map<char, int> data;
    char input;
    while(true){
        input = cin.get();
        if(input == '\n'){
            break;
        }
        if(isalpha(input)){
            input = tolower(input);
            auto iter = data.find(input);
            if(iter != data.end()){
                ++iter->second;
            }else{
                data.insert({input, 1});
            }
        }
    }
    Comparator compFunctor = [](pair<char, int> elem1, pair<char, int> elem2){
        return elem1.second > elem2.second;
    };
    set<pair<char, int>, Comparator> ordered_data(data.begin(), data.end(), compFunctor);
    int max_count = ordered_data.begin()->second;
    vector<pair<char, int>> alpha_ordered_data;
    for(auto const &item: ordered_data){
        if(item.second == max_count){
            alpha_ordered_data.push_back(item);
        }else{
            break;
        }
    }
    Comparator compFunctor2 = [](pair<char, int> elem1, pair<char, int> elem2){
        return elem1.first < elem2.first;
    };
    sort(alpha_ordered_data.begin(), alpha_ordered_data.end(), compFunctor2);
    for(auto const &item: alpha_ordered_data){
        cout << item.first << ' ' << item.second << endl;
    }
    return 0;
}
