//
//  main.cpp
//  reverse_chain_list_pat_1025
//
//  Created by Michael Hui on 9/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//
// 1. dump data could exist.

# include <iostream>
# include <vector>
# include <map>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;

class Node{
public:
    string _current;
    int _data;
    string _next;
    Node(const string &current, const int &data, const string &next){
        _current = current;
        _data = data;
        _next = next;
    };
    Node(){
        _current = "0";
        _data = 0;
        _next = "0";
    }
    Node(const Node &obj){
        _current = obj._current;
        _data = obj._data;
        _next = obj._next;
    }
};

int main(){
    string first_node_address;
    int points_num, reverse_per_n;
    cin >> first_node_address >> points_num >> reverse_per_n;
    map <string, Node> storing_list;
    string address, next;
    int data;
    for(int i = 0; i < points_num; ++i){
        cin >> address >> data >> next;
        storing_list[address] = Node(address, data, next);
    }
    vector <Node*> faked_linked_list;
    string temp_address = first_node_address;
    Node *temp_ptr;
    while(temp_address != "-1"){
        temp_ptr = &storing_list[temp_address];
        faked_linked_list.push_back(temp_ptr);
        temp_address = storing_list[temp_address]._next;
    }
    int index_before_remainder = -1, real_size = static_cast<int>(faked_linked_list.size());
    for(int i = reverse_per_n - 1; i < real_size; i += reverse_per_n){
        for(int j = i, k = 0; k < reverse_per_n; ++k, --j){
            cout << faked_linked_list[j]->_current << " ";
            cout << faked_linked_list[j]->_data << " ";
            if(j - 1 == -1){
                cout << faked_linked_list[i + 1]->_current << endl;
            }else{
                cout << faked_linked_list[j - 1]->_current << endl;
            }
        }
        index_before_remainder = i;
    }
    for(int i = index_before_remainder + 1; i < real_size; ++i){
        cout << faked_linked_list[i]->_current << " ";
        cout << faked_linked_list[i]->_data << " ";
        cout << faked_linked_list[i]->_next << endl;
    }
    faked_linked_list.clear();
    storing_list.clear();
    return 0;
}
