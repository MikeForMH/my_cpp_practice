//
//  main.cpp
//  remove_duplication_and_sort_xuetangx_c10_2
//
//  Created by Michael Hui on 7/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <functional>
# include <vector>
# include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unique;
using std::sort;
using std::less;

int main(){
    vector<double> number_set;
    int n;
    double input;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> input;
        number_set.push_back(input);
    }
    sort(number_set.begin(), number_set.end(), less<int>());
    auto iter = unique(number_set.begin(), number_set.end());
    number_set.erase(iter, number_set.end());
    for(int i: number_set){
        cout << i << endl;
    }
    return 0;
}
