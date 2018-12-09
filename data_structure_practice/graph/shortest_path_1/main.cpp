//
//  main.cpp
//  shortest_path_1
//
//  Created by Michael Hui on 9/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <cstring>
# include <vector>
# include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;

class Graph{
private:
    int vertex;
    bool *visited;
    vector <int> *edges;
    int *distance;
public:
    Graph(const int &vertex_input){
        vertex = vertex_input;
        edges = new vector <int>[vertex];
        visited = new bool[vertex];
        memset(visited, false, vertex);
        distance = new int[vertex];
        memset(distance, 0, sizeof(int) * vertex);
    }
    ~Graph(){
        delete [] edges;
        delete [] visited;
        delete [] distance;
    };
    void insert_edge(const int &x, const int &y){
        edges[x - 1].push_back(y);
        edges[y - 1].push_back(x);
    }
    void bfs_from_given_vertex(const int &input_vertex){
        queue <int> bfs_queue;
        bfs_queue.push(input_vertex);
        visited[input_vertex - 1] = true;
        distance[input_vertex - 1] = 0;
        while(!bfs_queue.empty()){
            int current_visiting = bfs_queue.front();
            bfs_queue.pop();
            for(int adj_vertex: edges[current_visiting - 1]){
                if(!visited[adj_vertex - 1]){
                    visited[adj_vertex - 1] = true;
                    bfs_queue.push(adj_vertex);
                    distance[adj_vertex - 1] = distance[current_visiting - 1] + 1;
                }
            }
        }
        for(int i = 0; i < vertex; ++i){
            cout << distance[i] << endl;
        }
        return;
    }
};

int main(){
    int n, m, c;
    cin >> n >> m >> c;
    Graph graph(n);
    for(int i = 0, x, y; i < m; ++i){
        cin >> x >> y;
        graph.insert_edge(x, y);
    }
    graph.bfs_from_given_vertex(c);
    return 0;
}
