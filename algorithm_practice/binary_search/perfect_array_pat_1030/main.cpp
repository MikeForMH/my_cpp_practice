//
//  main.cpp
//  perfect_array_pat_1030
//
//  Created by Michael Hui on 12/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//
//  1.numbers got duplications
//  2.use your pen to confirm where is the edge

# include <iostream>
# include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::fill_n;
# define MAX 100001

int bi_search(long *input, const int &left, const int &right, const long &key){
    int low_bound = left;
    int high_bound = right;
    while(low_bound <= high_bound){
        int mid = (low_bound + high_bound) / 2;
        if(key == input[mid]){
            while(input[mid + 1] == key){
                ++mid;
            }
            return mid;
        }
        else if(key > input[mid]){
            low_bound = mid + 1;
        }
        else{
            high_bound = mid - 1;
        }
    }
    while(input[low_bound - 1] == input[low_bound]){
        ++low_bound;
    }
    return low_bound - 1;
}

int main(){
    long p, temp; int n;
    long list[MAX]; fill_n(list, MAX, -1);
    cin >> n >> p;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        list[i] = temp;
    }
    sort(list, list + n);
    int max_count = 0;
    long new_max = -1;
    for(int i = 0; n - i > max_count; ++i){
        // if current max_count is even greater than the size of maximum possible
        // perfect array that could be construct from the remaining sorted array,
        // then there is no meed to continue the comparing.
        new_max = list[i] * p;
        int new_index = bi_search(list, i, n - 1, new_max);
        //cout << new_index << " ";
        //cout << new_index - i + 1  << endl;
        if(new_index - i + 1 > max_count){
            max_count = new_index - i + 1;
        }
    }
    cout << max_count << endl;
    return 0;
}
