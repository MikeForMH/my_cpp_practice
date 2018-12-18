//
//  main.cpp
//  shortest_path_3
//
//  Created by Michael Hui on 10/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <cstring>
# include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::queue;

class Point{
public:
    int row;
    int column;
    Point(){
        row = -1;
        column = -1;
    }
};

//int adj_pt_coordinate[8][2] = {-2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2};

class Chess_Board{
private:
    int height;
    int length;
    int **distance;
    bool **visited;
    bool **map;
    Point start_point;
    Point end_point;
    static int adj_pt_coordinate[8][2];
    static int restrict_position[4][2];
public:
    Chess_Board(int &input_height, int &input_length){
        height = input_height + 4;
        length = input_length + 4;
        visited = new bool* [height];
        distance = new int* [height];
        map = new bool* [height];
        for(int i = 0; i < height; ++i){
            visited[i] = new bool [length];
            distance[i] = new int [length];
            map[i] = new bool [length];
            memset(visited[i], true, length);
            memset(distance[i], 0, sizeof(int) * length);
            memset(map[i], false, length);
        }
        for(int i = 2; i < height - 2; ++i){
            for(int j = 2; j < length - 2; ++j){
                visited[i][j] = false;
            }
        }
    }
    ~Chess_Board(){
        for(int i = 0; i < height; ++i){
            delete [] visited[i];
            delete [] distance[i];
        }
        delete [] visited;
        delete [] distance;
    }
    void insert_block(int &row, int &column){
        map[row][column] = true;
        return;
    }
    void set_start_point(int &row, int &column){
        start_point.row = row;
        start_point.column = column;
        return;
    }
    void set_end_point(int &row, int &column){
        end_point.row = row;
        end_point.column = column;
        return;
    }
    void bfs_of_horse(){
        queue <Point> bfs_queue;
        bfs_queue.push(start_point);
        visited[start_point.row][start_point.column] = true;
        distance[start_point.row][start_point.column] = 0;
        while(!bfs_queue.empty()){
            Point current_point = bfs_queue.front();
            bfs_queue.pop();
            Point adjacent_point;
            Point restrict_point;
            for(int i = 0; i < 8; ++i){
                adjacent_point.row = current_point.row + adj_pt_coordinate[i][0];
                adjacent_point.column = current_point.column + adj_pt_coordinate[i][1];
                restrict_point.row = current_point.row + restrict_position[i/2][0];
                restrict_point.column = current_point.column + restrict_position[i/2][1];
                if((!map[restrict_point.row][restrict_point.column]) && (!visited[adjacent_point.row][adjacent_point.column]) && (!map[adjacent_point.row][adjacent_point.column])){
                    visited[adjacent_point.row][adjacent_point.column] = true;
                    distance[adjacent_point.row][adjacent_point.column] = distance[current_point.row][current_point.column] + 1;
                    bfs_queue.push(adjacent_point);
                    if(adjacent_point.row == end_point.row && adjacent_point.column == end_point.column){
                        cout << distance[adjacent_point.row][adjacent_point.column] << endl;
                        return;
                    }
                }
            }
        }
        cout << -1 << endl;
        return;
    }
};

int Chess_Board::adj_pt_coordinate[8][2] = {-2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2};
int Chess_Board::restrict_position[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

int main(){
    int n, m;
    cin >> n >> m;
    char map_input;
    Chess_Board chess_board(n, m);
    for(int i = 2; i < n + 2; ++i){
        for(int j = 2; j < m + 2; ++j){
            cin >> map_input;
            switch(map_input){
                case '.':
                    break;
                case '#':
                    chess_board.insert_block(i, j);
                    break;
                case 's':
                    chess_board.set_start_point(i, j);
                    break;
                case 'e':
                    chess_board.set_end_point(i, j);
                    break;
            }
        }
    }
    chess_board.bfs_of_horse();
    return 0;
}
