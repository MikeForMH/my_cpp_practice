//
//  main.cpp
//  find_two_number_with_specific_sum
//
//  Created by Michael Hui on 19/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void find_two_number_with_specific_sum(vector <int> &input_array, int &target_sum){
    int count = static_cast <int>(input_array.size());
    vector <int> hash_table[1001];
    for(int i = 1; i <= count; ++i){
        hash_table[input_array[i - 1]].push_back(i);
    }
    int component;
    for(int i = 0; i < count; ++i){
        component = target_sum - input_array[i];
        if(!hash_table[component].empty() && component >= 0){
            cout << i + 1 << " " << hash_table[component][0] << endl;
            return;
        }
    }
    cout << "something went wrong" << endl;
    return;
}

int main(){
    vector <int> input_array;
    int n, input_number, target_sum;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> input_number;
        input_array.push_back(input_number);
    }
    cin >> target_sum;
    find_two_number_with_specific_sum(input_array, target_sum);
    return 0;
}
