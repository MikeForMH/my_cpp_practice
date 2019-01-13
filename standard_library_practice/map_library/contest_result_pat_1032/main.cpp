//
//  main.cpp
//  contest_result_pat_pat_1032
//
//  Created by Michael Hui on 13/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <map>
# include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::max_element;
using std::pair;

bool compare(const pair<int, int>&a, const pair<int, int>&b){
    return a.second < b.second;
}

int main(){
    map<int, int> contest_result;
    int n, school, score;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> school >> score;
        contest_result[school] += score;
    }
    auto iter = max_element(contest_result.begin(), contest_result.end(), compare);
    cout << iter->first << " " << iter->second << endl;
    return 0;
}
