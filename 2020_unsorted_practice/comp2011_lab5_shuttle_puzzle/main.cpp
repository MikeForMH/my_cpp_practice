//
//  main.cpp
//  comp_2011_lab5_shuttle_puzzle
//
//  Created by Michael Hui on 24/3/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::swap;
using std::to_string;

void init_ref(string &ref, const int &length){
    ref = '[';
    for(int i = 0; i < length + 1; ++i){
        ref += to_string(i);
    }
    ref += ']';
    return;
}

void init_puzzle(vector <char> &puzzle, const int &num_W, const int &num_B){
    for(int i = 0; i < num_W; ++i){
        puzzle.push_back('W');
    }
    puzzle.push_back('.');
    for(int i = 0; i < num_B; ++i){
        puzzle.push_back('B');
    }
    return;
}

bool is_moved(vector <char> &puzzle, const int &index, const char &direction){
    switch (direction) {
        case 'J':
            switch (puzzle[index]) {
                case 'W':
                    if(index > puzzle.size() - 3){ // make sure not out of range first
                        return false;
                    }
                    if(puzzle[index + 1] != 'B' || puzzle[index + 2] != '.'){
                        return false;
                    }
                    swap(puzzle[index], puzzle[index + 2]);
                    return true;
                case 'B':
                    if(index < 2){
                        return false;
                    }
                    if(puzzle[index - 1] != 'W' || puzzle[index - 2] != '.'){
                        return false;
                    }
                    swap(puzzle[index], puzzle[index - 2]);
                    return true;
            }
        case 'S':
            switch (puzzle[index]) {
                case 'W':
                    if(index > puzzle.size() - 2){
                        return false;
                    }
                    if(puzzle[index + 1] != '.'){
                        return false;
                    }
                    swap(puzzle[index], puzzle[index + 1]);
                    return true;
                case 'B':
                    if(index < 1){
                        return false;
                    }
                    if(puzzle[index - 1] != '.'){
                        return false;
                    }
                    swap(puzzle[index], puzzle[index - 1]);
                    return true;
            }
    }
    return false;
}

void print_puzzle(const vector <char> &puzzle){
    for(const auto &i: puzzle){
        cout << i;
    }
    cout << endl;
    return;
}

bool is_win(const vector <char> &puzzle, const int &num_W, const int &num_B){
    for(int i = 0; i < num_B; ++i){
        if(puzzle[i] != 'B'){
            return false;
        }
    }
    if(puzzle[num_B] != '.'){
        return false;
    }
    for(int i = num_B + 1; i < puzzle.size(); ++i){
        if(puzzle[i] != 'W'){
            return false;
        }
    }
    return true;
}

int main(){
    int num_W = 0;
    int num_B = 0;
    int input_index = 0;
    char input_char = ' ';
    cout << "Num of white and black marbles: ";
    cin >> num_W >> num_B;
    string ref;
    init_ref(ref, num_W + num_B);
    vector <char> puzzle;
    init_puzzle(puzzle, num_W, num_B);
    while(true){
        cout << ref << endl;
        print_puzzle(puzzle);
        if(is_win(puzzle, num_W, num_B)){
            cout << "Congratulations!" << endl;
            break;
        }
        cout << "Index (-1 to exit): ";
        cin >> input_index;
        if(input_index == -1){
            cout << "Exit." << endl;
            break;
        }
        cout << "J' or 'S': ";
        cin >> input_char;
        if(!is_moved(puzzle, input_index, input_char)){
            cout << "Error!" << endl;
        }
    }
    return 0;
}
