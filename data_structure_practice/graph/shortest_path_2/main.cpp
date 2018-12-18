//
//  main.cpp
//  shortest_path_2
//
//  Created by Michael Hui on 9/12/2018.
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
    Point(int &input_row, int &input_column){
        row = input_row;
        column = input_column;
    }
    Point(){
        row = -1;
        column = -1;
    }
};

class Labyrinth{
private:
    int length;
    int height;
    int given_time;
    int **distance;
    bool **visited;
    Point start_point;
    Point end_point;
public:
    Labyrinth(int &input_length, int &input_height, int &input_time){
        height = input_height + 2;
        length = input_length + 2;
        given_time = input_time;
        visited = new bool* [height];
        for(int i = 0; i < height; ++i){
            visited[i] = new bool [length];
            memset(visited[i], false, length);
        }
        for(int i = 0; i < height; ++i){
            visited[i][0] = true;
            visited[i][length - 1] = true;
        }
        for(int j = 0; j < length; ++j){
            visited[0][j] = true;
            visited[height - 1][j] = true;
        }
        distance = new int* [height];
        for(int i = 0; i < height; i++){
            distance[i] = new int [length];
            memset(distance[i], 1e6 + 1, sizeof(int) * length);
        }
    }
    ~Labyrinth(){
        for(int i = 0; i < height; ++i){
            delete [] visited[i];
            delete [] distance[i];
        }
        delete [] visited;
        delete [] distance;
    }
    /*
    void insert_block(int &r, int &c){
        visited[r][c] = false;
        return;
    }
     */
    void initialize_start_pt(Point &start_p){
        start_point = start_p;
        return;
    }
    void initialize_end_pt(Point &end_p){
        end_point = end_p;
        return;
    }
    void bfs_time_of_given_points(){
        queue <Point> bfs_queue;
        bfs_queue.push(start_point);
        visited[start_point.row][start_point.column] = false;
        distance[start_point.row][start_point.column] = 0;
        while (!bfs_queue.empty()){
            Point current_point = bfs_queue.front();
            Point adjacent_point = current_point;
            bfs_queue.pop();
            for(int i = 0; i < 4; ++i){
                switch(i){
                    case 0:
                        adjacent_point.row += 1;
                        break;
                    case 1:
                        adjacent_point.row -= 1;
                        adjacent_point.column += 1;
                        break;
                    case 2:
                        adjacent_point.column -= 1;
                        adjacent_point.row -= 1;
                        break;
                    case 3:
                        adjacent_point.row += 1;
                        adjacent_point.column -= 1;
                        break;
                }
                if(!visited[adjacent_point.row][adjacent_point.column]){
                    visited[adjacent_point.row][adjacent_point.column] = true;
                    distance[adjacent_point.row][adjacent_point.column] = distance[current_point.row][current_point.column] + 1;
                    bfs_queue.push(adjacent_point);
                    if(adjacent_point.row == end_point.row && adjacent_point.column == end_point.column){
                        if(distance[end_point.row][end_point.column] <= given_time){
                            cout << "YES" << endl;
                        }
                        else{
                            cout << "NO" << endl;
                        }
                        return;
                    }
                }
            }
        }
        cout << "NO" << endl;
        return;
        /*
        if(distance[end_point.row][end_point.column] <= given_time){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        return;
         */
    }
    void make_visited(int &input_row, int &input_column){
        visited[input_row][input_column] = true;
        return;
    }
    void set_start_point(int &input_row, int &input_column){
        start_point.row = input_row;
        start_point.column = input_column;
        return;
    }
    void set_end_point(int &input_row, int &input_column){
        end_point.row = input_row;
        end_point.column = input_column;
        return;
    }
};

int main(){
    int n, m, t;
    char map_input;
    cin >> n >> m >> t;
    Labyrinth labyrinth(m, n, t);
    for (int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> map_input;
            switch(map_input){
                case '.':
                    break;
                case '*':
                    labyrinth.make_visited(i, j);
                    break;
                case 'P':
                    labyrinth.set_end_point(i, j);
                    break;
                case 'S':
                    labyrinth.set_start_point(i, j);
                    break;
            }
        }
    }
    labyrinth.bfs_time_of_given_points();
    return 0;
}
