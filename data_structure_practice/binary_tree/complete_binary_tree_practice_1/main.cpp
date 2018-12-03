//
//  main.cpp
//  complete_binary_tree_practice_1
//
//  Created by Michael Hui on 3/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <cmath>
using std::cin;
using std::cout;
using std::endl;

template <typename Type> class Stack{
private:
    Type *_data;
    int _max_size, _top_index, _count;
public:
    Stack(const int &size_input){
        _max_size = size_input;
        _data = new Type [_max_size];
        _top_index = -1;
        _count = 0;
    }
    ~Stack(){
        delete [] _data;
    }
    bool push(const Type &input_data){
        if(_top_index >= _max_size - 1){
            return false;
        }
        ++_top_index;
        _data[_top_index] = input_data;
        ++_count;
        return true;
    }
    bool pop(){
        if(_top_index <= -1){
            return false;
        }
        --_top_index;
        --_count;
        return true;
    }
    Type top(){
        if(_top_index <= -1){
            return false;
        }
        return _data[_top_index];
    }
    bool empty(){
        return _top_index <= -1;
    }
    int get_count(){
        return _count;
    }
};

template <typename Type> class Node{
public:
    Type _data;
    Node <Type> *_lchild, *_rchild;
    Node(const Type &input_data){
        _data = input_data;
        _lchild = NULL;
        _rchild = NULL;
    }
    ~Node(){
        if(_lchild != NULL){
            delete _lchild;
        }
        if(_rchild != NULL){
            delete _rchild;
        }
    }
    void output_list(){
        cout << _data;
        if(_lchild != NULL || _rchild != NULL){
            cout << '(';
        }
        if(_lchild != NULL){
            _lchild->output_list();
        }
        if(_rchild != NULL){
            cout << ',';
        }
        if(_rchild != NULL){
            _rchild->output_list();
        }
        if(_lchild != NULL || _rchild != NULL){
            cout << ')';
        }
        return;
    }
};

template <typename Type> class Binary_Tree{
private:
    Node <Type> *_root;
    int _node_number;
public:
    Binary_Tree(){
        _root = NULL;
        _node_number = 0;
    }
    ~Binary_Tree(){
        delete _root;
    }
    void output_tree(){
        if(_root == NULL){
            return;
        }
        _root->output_list();
        cout << endl;
        return;
    }
    void insert_node(const Type &input_data){
        if(_root == NULL){
            _root = new Node <Type>(input_data);
            ++_node_number;
            return;
        }
        int layer_number = static_cast <int> (floor(log(_node_number + 1)/log(2)));
        Stack <int> path(layer_number);
        //for example, path 010011 need a stack of size 6
        int remainder = _node_number + 1;
        while(remainder != 1){
            path.push(remainder % 2);
            remainder /= 2;
        }
        Node <Type> *current_node = _root;
        while(layer_number != 1){
            if(path.top() == 0){
                current_node = current_node->_lchild;
                path.pop();
            }
            else{
                current_node = current_node->_rchild;
                path.pop();
            }
            --layer_number;
        }
        Node <Type> *new_node = new Node <Type>(input_data);
        if(path.top() == 0){
            current_node->_lchild = new_node;
        }
        else{
            current_node->_rchild = new_node;
        }
        ++_node_number;
        return;
    }
};

int main(){
    char input_data;
    Binary_Tree <char> binary_tree;
    cin >> input_data;
    while(input_data != '$'){
        binary_tree.insert_node(input_data);
        cin >> input_data;
    }
    binary_tree.output_tree();
    return 0;
}
