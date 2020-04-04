//
//  main.cpp
//  comp2011_lab7_lights_out_my_implementation
//
//  Created by Michael Hui on 3/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <random>
#include <iomanip>
#define WIDTH 3

using std::cin;
using std::cout;
using std::endl;
using std::setw;

class grid{
public:
    grid(){
        this->size = 0;
        grid_pt = nullptr;
        return;
    }
    grid(const int &size){
        this->size = size;
        this->grid_pt = new bool*[size];
        for(int i = 0; i < size; ++i){
            this->grid_pt[i] = new bool[size]();
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, 1);
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j){
                if(dis(gen)){
                    flip(i, j);
                    // may store solver here;
                }
            }
        }
        return;
    }
    ~grid(){
        for(int i = 0; i < size; ++i){
            delete [] grid_pt[i];
        }
        delete [] grid_pt;
    }
    void flip(const int &x, const int &y){
        exchange(x, y);
        if(x > 0){
            exchange(x - 1, y);
        }
        if(x < size - 1){
            exchange(x + 1, y);
        }
        if(y > 0){
            exchange(x, y - 1);
        }
        if(y < size - 1){
            exchange(x, y + 1);
        }
        return;
    }
    void print_grid(){
        cout << std::setiosflags(std::ios::left);
        cout << setw(WIDTH) << '\0' << setw(WIDTH) << '\n';
        for(int i = 0; i < size; ++i){
            cout << setw(WIDTH) << i;
        }
        cout << endl;
        cout << setw(WIDTH) << '\0' << setw(WIDTH) << '+';
        for(int i = 0; i < size; ++i){
            cout << setw(WIDTH) << '-';
        }
        cout << endl;
        for(int i = 0; i < size; ++i){
            cout << setw(WIDTH) << i << setw(WIDTH) << '|';
            for(int j = 0; j < size; ++j){
                if(grid_pt[i][j]){
                    cout << setw(WIDTH) << 'O';
                }else{
                    cout << setw(WIDTH) << '.';
                }
                
            }
            cout << endl;
        }
        return;
    }
private:
    bool **grid_pt;
    int size;
    void exchange(const int &x, const int &y){
        if(grid_pt[x][y]){
            grid_pt[x][y] = false;
        }else{
            grid_pt[x][y] = true;
        }
        return;
    }
};

int main(){
    int size_of_grid = 0;
    bool need_solver = false;
    cout << "Welcome to Lights Out Puzzle!\n"
         << "Please input the size.";
    cin >> size_of_grid;
    cout << "Do you want the solution? (1-Yes / 0-No)";
    cin >> need_solver;
    grid game_grid(size_of_grid);
    
}
