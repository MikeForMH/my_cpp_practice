//
//  main.cpp
//  greatest_number_smaller_than_given_number_2
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
    return 0;
}
