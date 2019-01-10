//
//  main.cpp
//  reverse_chain_list_pat_1025
//
//  Created by Michael Hui on 9/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//
// 1. dump data could exist.

# include <iostream>
# include <string>
# include <vector>
# include <map>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
using std::stoi;

struct Node{
    string _current;
    string _data;
    string _next;
    Node(string &c, string &d, string &n){
        _current = c;
        _data = d;
        _next = n;
    }
    Node(){
        _current = {};
        _data = {};
        _next = {};
    }
    Node(const Node &obj){
        _current = obj._current;
        _data = obj._data;
        _next = obj._next;
    }
};

bool is_valid_current(const string &input){
    if(stoi(input) >= 0 && stoi(input) <= 99999){
        return true;
    }else{
        return false;
    }
}
bool is_valid_next(const string &input){
    if(stoi(input) >= -1 && stoi(input) <= 99999){
        return true;
    }else{
        return false;
    }
}

int main(){
    string first_node_address;
    int number_of_nodes, reverse_per_n;
    cin >> first_node_address >> number_of_nodes >> reverse_per_n;
    map<string, Node> storing_list;
    for(int i = 0; i < number_of_nodes; ++i){
        string address, data, next;
        cin >> address >> data >> next;
        if(is_valid_current(address) && is_valid_next(next)){
            storing_list[address] = Node(address, data, next);
        }
    }
    if(!is_valid_current(first_node_address)){
        return 0;
    }
    vector <Node*> original_linked_list;
    string iterating_address = first_node_address;
    while(iterating_address != "-1"){
        original_linked_list.push_back(&storing_list[iterating_address]);
        iterating_address = storing_list[iterating_address]._next;
    }
    int actual_size = static_cast<int>(original_linked_list.size());
    vector <Node*> reversed_linked_list;
    for(int i = reverse_per_n - 1; i < actual_size; i += reverse_per_n){
        for(int j = i; j > i - reverse_per_n; --j){
            reversed_linked_list.push_back(original_linked_list[j]);
        }
    }
    for(int i = actual_size - actual_size % reverse_per_n; i < actual_size; ++i){
        reversed_linked_list.push_back(original_linked_list[i]);
    }
    string parameter_temp = "-1";
    Node last_node(parameter_temp, parameter_temp, parameter_temp);
    reversed_linked_list.push_back(&last_node);
    for(int i = 0; i < actual_size; ++i){
        cout << reversed_linked_list[i]->_current << " ";
        cout << reversed_linked_list[i]->_data << " ";
        cout << reversed_linked_list[i + 1]->_current << endl;
    }
    return 0;
}
