//
//  main.cpp
//  pat_1053
//
//  Created by Michael Hui on 29/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::setprecision;
using std::fixed;

int main() {
    int tenant_num = 0;
    double low_consumpt_threshold = 0;
    int low_consumpt_day_threshold = 0;
    int observation_period = 0;
    double consumpt_input = 0;
    double possible_vacant = 0;
    double vacant = 0;
    cin >> tenant_num >> low_consumpt_threshold >> low_consumpt_day_threshold;
    vector<vector<double>> data;
    for(int i = 0; i < tenant_num; ++i){
        vector<double> temp;
        data.push_back(temp);
        cin >> observation_period;
        for(int j = 0; j < observation_period; ++j){
            cin >> consumpt_input;
            data[i].push_back(consumpt_input);
        }
    }
    for(const auto& i: data){
        int low_consumpt_day = 0;
        for(const auto& j: i){
            if(j < low_consumpt_threshold){
                ++low_consumpt_day;
            }
        }
        if(low_consumpt_day > (i.size() / 2)){
            ++possible_vacant;
            if(i.size() > low_consumpt_day_threshold){
                ++vacant;
            }
        }
    }
    possible_vacant = (possible_vacant - vacant) / tenant_num * 100;
    vacant = vacant / tenant_num * 100;
    cout << fixed << setprecision(1);
    cout << possible_vacant << "% " << vacant << "%" << endl;
    return 0;
}
