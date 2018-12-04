//
//  main.cpp
//  adjacency_list_practice_1
//
//  Created by Michael Hui on 4/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
using std::cin;
using std::cout;
using std::endl;

class LinkedListNode {
public:
    int vertex;
    LinkedListNode *next;
    LinkedListNode(int vertex_input) {
        vertex = vertex_input;
        next = NULL;
    }
};
class LinkedList {
public:
    LinkedListNode *head;
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        while (head != NULL) {
            LinkedListNode *delete_node = head;
            head = head->next;
            delete delete_node;
        }
    }
    void insert(int vertex) {
        LinkedListNode *node = new LinkedListNode(vertex);
        node->next = head;
        head = node;
    }
};
class Graph {
private:
    LinkedList *edges;
    int points;
public:
    Graph(const int &point_number){
        points = point_number;
        edges = new LinkedList [points];
    }
    ~Graph(){
        delete [] edges;
    }
    void insert_by_given_condition(int &a, int &x, int&y){
        switch(a){
            case 0:
                edges[x].insert(y);
                return;
            case 1:
                edges[x].insert(y);
                edges[y].insert(x);
                return;
        }
    }
    void output_adjacency_list(){
        for(int i = 0; i < points; ++i){
            cout << i << ":";
            for(auto j = edges[i].head; j != NULL; j = j->next){
                cout << " " << j->vertex;
            }
            cout << endl;
        }
        return;
    }
};
int main() {
    int n, m, a, x, y;
    cin >> n >> m;
    Graph graph(n);
    for(int i = 0; i < m; ++i){
        cin >> a >> x >> y;
        graph.insert_by_given_condition(a, x, y);
    }
    graph.output_adjacency_list();
    return 0;
}
