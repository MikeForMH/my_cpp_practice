//
//  main.cpp
//  greatest_number_smaller_than_given_number_3
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
using std::swap;

void number_game(vector <int> &player_number, vector <int> given_number){
    int players = static_cast <int> (player_number.size());
    int rounds = static_cast <int> (given_number.size());
    for(int i = 0; i < rounds; ++i){
        if(given_number[i] <= player_number[0]){
            if(i != 0){
                cout << " ";
            }
            cout << player_number[0];
            continue;
        }
        int left = 0, right = players - 1, mid;
        while(left < right){
            mid = right - (right - left) / 2;
            if(player_number[mid] <= given_number[i]){
                left = mid;
            }
            else{
                right = mid - 1;
            }
        }
        if(i != 0){
            cout << " ";
        }
        cout << player_number[left];
    }
}

void ascending_qucik_sort(vector <int> &input_array, int left, int right){
    if(left < right){
        int i = left, j = left;
        int pivot = input_array[right];
        for(; j < right; ++j){
            if(input_array[j] < pivot){
                swap(input_array[i], input_array[j]);
                ++i;
            }
        }
        swap(input_array[right], input_array[i]);
        ascending_qucik_sort(input_array, left, i - 1);
        ascending_qucik_sort(input_array, i + 1, right);
    }
    return;
}

int main(){
    int players, rounds, input_number;
    vector <int> player_number, given_number;
    cin >> players >> rounds;
    for(int i = 0; i < players; ++i){
        cin >> input_number;
        player_number.push_back(input_number);
    }
    for(int i = 0; i < rounds; ++i){
        cin >> input_number;
        given_number.push_back(input_number);
    }
    ascending_qucik_sort(player_number, 0, static_cast <int> (player_number.size() - 1));
    number_game(player_number, given_number);
    return 0;
}

