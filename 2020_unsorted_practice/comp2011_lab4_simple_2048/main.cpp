//
//  main.cpp
//  comp2011_lab4_simple_2048
//
//  Created by Michael Hui on 16/3/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>
#include <algorithm>
#define X_SIZE 4
#define Y_SIZE 4
#define WIN_VALUE 32

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct num_index{
    int x = 0;
    int y = 0;
};

void print_board(int (&board)[X_SIZE][Y_SIZE]){
    const char fill = ' ';
    const int width = 5;
    for(int i = 0; i < Y_SIZE; ++i){
        for(int j = 0; j < X_SIZE; ++j){
            cout << std::left << std::setw(width) << std::setfill(fill) << board[i][j];
        }
        cout << endl;
    }
    return;
}

bool is_inserted(int (&board)[X_SIZE][Y_SIZE]){ // the return type does not matter
    vector <num_index> avail_space;
    int empty_count = 0;
    for(int i = 0; i < Y_SIZE; ++i){
        for(int j = 0; j < X_SIZE; ++j){
            if(board[i][j] == 0){
                num_index temp;
                temp.x = j;
                temp.y = i;
                avail_space.push_back(temp);
                empty_count++;
            }
        }
    }
    if(empty_count == 0){
        return false;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis_1(0, empty_count - 1);
    std::uniform_int_distribution<> dis_2(0, 1);
    int target = dis_1(gen);
    //cout << "target:" << target << endl;
    int insert_value = 0;
    if(dis_2(gen)){
        insert_value = 2;
    }else{
        insert_value = 4;
    }
    board[avail_space[target].y][avail_space[target].x] = insert_value;
    return true;
}

bool move(const char &direction, int (&board)[Y_SIZE][X_SIZE], int &line){
    bool is_moved = false;
    vector <int> temp;
    switch (direction) {
        case 'a':
            for(int i = 0; i < Y_SIZE; ++i){
                if(board[line][i] != 0){
                    temp.push_back(board[line][i]);
                }
            }
            if(temp.empty()){ // everything is 0 in that line
                return is_moved;
            }
            for(int i = 1; i < temp.size(); ++i){
                if(temp[i - 1] == temp[i]){
                    temp[i - 1] *= 2;
                    temp[i] = 0;
                    i += 2;
                    is_moved = true;
                }
            }
            for(int i = 0; i < temp.size(); ++i){
                if(board[line][i] != temp[i]){
                    is_moved = true;
                    break;
                }
            }
            if(!is_moved){ // something is not zero but nothing moved
                return is_moved;
            }
            temp.erase(std::remove(temp.begin(), temp.end(), 0), temp.end());
            for(int i = 0; i < Y_SIZE; ++i){
                board[line][i] = 0;
            }
            for(int i = 0; i < temp.size(); ++i){
                board[line][i] = temp[i];
            }
            return is_moved;
            //break;
        case 'd':
            for(int i = Y_SIZE - 1; i >= 0; --i){
                if(board[line][i] != 0){
                    temp.push_back(board[line][i]);
                }
            }
            if(temp.empty()){ // everything is 0 in that line
                return is_moved;
            }
            for(int i = 1; i < temp.size(); ++i){
                if(temp[i - 1] == temp[i]){
                    temp[i - 1] *= 2;
                    temp[i] = 0;
                    i += 2;
                    is_moved = true;
                }
            }
            for(int i = 0, j = Y_SIZE - 1; i < temp.size(); ++i, --j){
                if(board[line][j] != temp[i]){
                    is_moved = true;
                }
            }
            if(!is_moved){ // something is not zero but nothing moved
                return is_moved;
                break;
            }
            temp.erase(std::remove(temp.begin(), temp.end(), 0), temp.end());
            for(int i = 0; i < Y_SIZE; ++i){
                board[line][i] = 0;
            }
            for(int i = 0; i < temp.size(); ++i){
                board[line][Y_SIZE - i - 1] = temp[i];
            }
            return is_moved;
        case 'w':
            for(int i = 0; i < X_SIZE; ++i){
                if(board[i][line] != 0){
                    temp.push_back(board[i][line]);
                }
            }
            if(temp.empty()){ // everything is 0 in that line
                return is_moved;
            }
            for(int i = 1; i < temp.size(); ++i){
                if(temp[i - 1] == temp[i]){
                    temp[i - 1] *= 2;
                    temp[i] = 0;
                    i += 2;
                    is_moved = true;
                }
            }
            for(int i = 0; i < temp.size(); ++i){
                if(board[i][line] != temp[i]){
                    is_moved = true;
                    break;
                }
            }
            if(!is_moved){ // something is not zero but nothing moved
                return is_moved;
            }
            temp.erase(std::remove(temp.begin(), temp.end(), 0), temp.end());
            for(int i = 0; i < X_SIZE; ++i){
                board[i][line] = 0;
            }
            for(int i = 0; i < temp.size(); ++i){
                board[i][line] = temp[i];
            }
            return is_moved;
        case 's':
            for(int i = X_SIZE - 1; i >= 0; --i){
                if(board[i][line] != 0){
                    temp.push_back(board[i][line]);
                }
            }
            if(temp.empty()){ // everything is 0 in that line
                return is_moved;
            }
            for(int i = 1; i < temp.size(); ++i){ // if something is combined
                if(temp[i - 1] == temp[i]){
                    temp[i - 1] *= 2;
                    temp[i] = 0;
                    i += 2;
                    is_moved = true;
                }
            }
            for(int i = 0, j = X_SIZE - 1; i < temp.size(); ++i, --j){ // if nothing moved
                if(board[j][line] != temp[i]){
                    is_moved = true;
                    break;
                }
            }
            if(!is_moved){ // something is not zero but nothing moved
                return is_moved;
            }
            temp.erase(std::remove(temp.begin(), temp.end(), 0), temp.end());
            for(int i = 0; i < X_SIZE; ++i){
                board[i][line] = 0;
            }
            for(int i = 0; i < temp.size(); ++i){
                board[X_SIZE - 1 - i][line] = temp[i];
            }
            return is_moved;
    }
    return false;
}


bool slide(const char &direction, int (&board)[Y_SIZE][X_SIZE]){
    bool is_valid_move = false;
    if(direction == 'a' || direction == 'd'){
        for(int i = 0; i < X_SIZE; ++i){
            if(move(direction, board, i)){
                is_valid_move = true;
            }
        }
    }else{
        for(int i = 0; i < Y_SIZE; ++i){
            if(move(direction, board, i)){
                is_valid_move = true;
            }
        }
    }
    return is_valid_move;
}

bool is_lose(int (&board)[Y_SIZE][X_SIZE]){
    for(int i = 0; i < X_SIZE - 1; ++i){
        for(int j = 0; j < Y_SIZE - 1; ++j){
            if(board[j][i] == board[j][i + 1]){
                return false;
            }
            if(board[j][i] == board[j + 1][i]){
                return false;
            }
        }
    }
    for(int i = 0; i < X_SIZE - 1; ++i){
        if(board[Y_SIZE - 1][i] == board[Y_SIZE - 1][i + 1]){
            return false;
        }
    }
    for(int i = 0; i < Y_SIZE - 1; ++i){
        if(board[i][X_SIZE - 1] == board[i + 1][X_SIZE - 1]){
            return false;
        }
    }
    for(int i = 0; i < X_SIZE; ++i){
        for(int j = 0; j < Y_SIZE; ++j){
            if(board[j][i] == 0){
                return false;
            }
        }
    }
    return true;
}

bool is_win(int (&board)[Y_SIZE][X_SIZE]){
    for(int i = 0; i < X_SIZE; ++i){
        for(int j = 0; j < Y_SIZE; ++j){
            if(board[j][i] == WIN_VALUE){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int board [Y_SIZE][X_SIZE] = {0};
    char input_direction;
    cout << "Welcome to 2048 Game!\n" <<
            "input w|a|s|d to slide the tiles.\n" <<
            "Game start! Get 32 to win!\n";
    is_inserted(board);
    print_board(board);
    for(;;){
        
        cin >> input_direction;
        if(!slide(input_direction, board)){
            cout << "Invalid move!" << endl;
            print_board(board);
            continue;
        }
        is_inserted(board);
        print_board(board);
        if(is_lose(board)){
            cout << "Game Over!" << endl;
            break;
        }
        if(is_win(board)){
            cout << "Congratulations! You Win!" << endl;
            break;
        }
    }
    return 0;
}
