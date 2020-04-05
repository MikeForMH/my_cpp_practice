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
#include <utility>
#include <set>

#define WIDTH 3
#define USE_DEFAULT_SOLVER true

using std::cin;
using std::cout;
using std::endl;
using std::setw;

typedef std::set<std::pair<int, int>> Coordinates;

class Grid{
public:
    Grid(){
        this->size = 0;
        grid_pt = nullptr;
        return;
    }
    Grid(const int &size, const bool &solver_option){
        this->use_default_solver = solver_option;
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
                    solver_default.insert(std::make_pair(i, j));
                }
            }
        }
        if(!use_default_solver){
            initialize_solver_enum();
        }
        return;
    }
    ~Grid(){
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
        Coordinates *current_solver;
        if(use_default_solver){
            current_solver = &solver_default;
        }else{
            current_solver = &solver_enum;
        }
        if(current_solver->erase(std::make_pair(x, y)) == 0){
            current_solver->insert(std::make_pair(x, y));
        }
        return;
    }
    void print_grid(){
        cout << std::setiosflags(std::ios::left);
        cout << setw(WIDTH) << ' ' << setw(WIDTH) << ' ';
        for(int i = 0; i < size; ++i){
            cout << setw(WIDTH) << i;
        }
        cout << endl;
        cout << setw(WIDTH) << ' ' << setw(WIDTH) << '+';
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
        cout << std::resetiosflags(std::ios::left);
        return;
    }
    void print_solver(){
        if(use_default_solver){
            for(auto const &item: solver_default){
                cout << '(' << item.first << ',' << item.second << ") ";
            }
        }else{
            for(auto const &item: solver_enum){
                cout << '(' << item.first << ',' << item.second << ") ";
            }
        }
        cout << endl;
        return;
    }
    bool is_win(){
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j){
                if(grid_pt[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool **grid_pt;
    int size;
    Coordinates solver_default;
    Coordinates solver_enum;
    bool use_default_solver;
    void exchange(const int &x, const int &y){
        if(grid_pt[x][y]){
            grid_pt[x][y] = false;
        }else{
            grid_pt[x][y] = true;
        }
        return;
    }
    void initialize_solver_enum(){
        
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
    Grid game_grid(size_of_grid, USE_DEFAULT_SOLVER);
    game_grid.print_grid();
    if(need_solver){
        game_grid.print_solver();
    }
    int x_input = 0;
    int y_input = 0;
    while(!game_grid.is_win()){
        cout << "Please choose a location (x, y)\n";
        cin >> x_input >> y_input;
        game_grid.flip(x_input, y_input);
        game_grid.print_grid();
        if(need_solver && !game_grid.is_win()){
            cout << "Solution:\n";
            game_grid.print_solver();
        }
    }
    cout << "\n******Congratulations!******\n";
    return 0;
}

