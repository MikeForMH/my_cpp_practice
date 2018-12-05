//
//  main.cpp
//  adjacency_matrix_practice_1
//
//  Created by Michael Hui on 5/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::memset;

class Graph{
private:
    int _node;
    int **_adjacency_matrix;
public:
    Graph(const int &node_number){
        _node = node_number;
        _adjacency_matrix = new int* [_node];
        for(int i = 0; i < _node; ++i){
            _adjacency_matrix[i] = new int [_node];
            memset(_adjacency_matrix[i], 0, sizeof(int) * _node);
        }
    }
    ~Graph(){
        for(int i = 0; i < _node; ++i){
            delete [] _adjacency_matrix[i];
        }
        delete [] _adjacency_matrix;
    }
    void insert_directed_edge(const int &a, const int& b){
        _adjacency_matrix[a][b] = 1;
        return;
    }
    void output_test(){
        for(int i = 0; i < _node; ++i){
            for(int j = 0; j < _node; ++i){
                if(j != 0){
                    cout << " ";
                }
                cout << _adjacency_matrix[i][j];
            }
            cout << endl;
        }
        return;
    }
    int get_out_degree(const int &vertex){
        int result = 0;
        for(int i = 0; i < _node; ++i){
            result += _adjacency_matrix[vertex][i];
        }
        return result;
    }
    int get_in_degree(const int &vertex){
        int result = 0;
        for(int i = 0; i < _node; ++i){
            result += _adjacency_matrix[i][vertex];
        }
        return result;
    }
    void output_score(){
        for(int i = 0; i < _node; ++i){
            cout << get_in_degree(i) - get_out_degree(i) << endl;
        }
        return;
    }
};

int main(){
    int n, m, a, b;
    cin >> n >> m;
    Graph graph(n);
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        graph.insert_directed_edge(a, b);
    }
    graph.output_score();
}
