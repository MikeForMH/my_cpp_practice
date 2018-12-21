//
//  main.cpp
//  collatz_conjecture_2_pat_1005
//
//  Created by Michael Hui on 21/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::swap;

void quick_sort_descending(vector <int> &input_array, const int &left, const int &right){
    if(left < right){
        int i = left, j = left, pivot = input_array[right];
        while(j < right){
            if(input_array[j] > pivot){
                swap(input_array[i], input_array[j]);
                ++i;
            }
            ++j;
        }
        swap(input_array[i], input_array[j]);
        quick_sort_descending(input_array, left, i - 1);
        quick_sort_descending(input_array, i + 1, right);
    }
}

void find_key_number(vector <int> &input_array){
    if(input_array.empty()){
        return;
    }
    bool covered_number[101] = {false};
    for(auto value: input_array){
        int result_number = value;
        while(result_number != 1){
            if(result_number % 2 == 0){ // even
                result_number /= 2;
                if(result_number <= 100){
                    if(covered_number[result_number]){
                        break;
                    }
                    covered_number[result_number] = true;
                }
            }
            else{
                result_number = (result_number * 3 + 1) / 2; // need to be divided by 2, or maybe more number
                if(result_number <= 100){                    // will be considered as judged.
                    if(covered_number[result_number]){
                        break;
                    }
                    covered_number[result_number] = true;
                }
            }
        }
    }
    vector <int> key_number;
    for(auto value: input_array){
        if(!covered_number[value]){
            key_number.push_back(value);
        }
    }
    quick_sort_descending(key_number, 0, static_cast<int>(key_number.size()) - 1);
    for(size_t i = 0; i < key_number.size(); ++i){
        if(i != 0){
            cout << " ";
        }
        cout << key_number[i];
    }
    cout << endl;
    return;
}

int main(){
    int n, input_number;
    vector <int> input_array;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> input_number;
        input_array.push_back(input_number);
    }
    find_key_number(input_array);
    return 0;
}
