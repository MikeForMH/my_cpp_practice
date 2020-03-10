//
//  main.cpp
//  insert_and_merge_pat_1035
//
//  Created by Michael Hui on 16/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::log;

int main(){
    vector<int> original_list, input_list;
    int n, input;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> input;
        original_list.push_back(input);
    }
    for(int i = 0; i < n; ++i){
        cin >> input;
        input_list.push_back(input);
    }
    bool is_merge = true;
    for(int i = 1; i <= n - 1; i += 2){
        if(input_list[i - 1] > input_list[i]){
            is_merge = false;
            break;
        }
    }
    if(is_merge){
        double sub_array_length = 0;
        for(int i = 1; i <= n - 1; ++i){
            if(input_list[i - 1] > input_list[i]){
                break;
            }
            ++sub_array_length;
        }
        int sorted_times = floor(log(sub_array_length)/log(2));
        vector<vector<int>> array;
        while(sub_array_length != 0){
            
        }
    }
}
