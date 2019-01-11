//
//  main.cpp
//  print_sandglass_pat_1027
//
//  Created by Michael Hui on 11/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//
//  0  1  2   3
//  1, 7, 17, 31
//  1  3  5   7

# include <iostream>
# include <vector>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void print_sandglass(int &count, char &symbol){
    int level_count_list[22] = {};
    level_count_list[0] = 1;
    int current_count = 1, i = 1;
    while(current_count < 1000){
        level_count_list[i] = level_count_list[i - 1] + 2 * (i * 2 + 1);
        current_count = level_count_list[i];
        ++i;
    }
    int low = 0, high = 21, level = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(count == level_count_list[mid]){
            level = mid;
            break;
        }
        else if(count < level_count_list[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    if(level == -1){
        level = high;
    }
    vector <string> output_element(level + 1);
    for(int i = level, k = 0; i >= 0; --i, ++k){
        for(int j = level - i; j > 0; --j){
            output_element[k].push_back(' ');
        }
        for(int j = 2 * i + 1; j > 0; --j){
            output_element[k].push_back(symbol);
        }
    }
    for(int i = 0; i <= level; ++i){
        cout << output_element[i] << endl;
    }
    for(int i = level - 1; i >= 0; --i){
        cout << output_element[i] << endl;
    }
    cout << count - level_count_list[level] << endl;
    return;
}

int main(){
    int count;
    char symbol;
    cin >> count >> symbol;
    print_sandglass(count, symbol);
    return 0;
}
