//
//  main.cpp
//  testing_ground
//
//  Created by Michael Hui on 16/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
# include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename Type> class Binary_Tree;

template <typename Type> class Stack{
private:
    Type *_data;
    int _max_size, _top_index, _count;
public:
    Stack(const int &input_size){
        _max_size = input_size;
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
        _rchild = NULL;
        _rchild = NULL;
    }
    ~Node(){
        //if(_lchild != NULL){
        //    delete _lchild;
        //}
        //if(_rchild != NULL){
        //    delete _rchild;
        //}
    }
    void output_list(){ // testing purpose
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
    Node <Type>* build_by_list(const string &input_string, Binary_Tree <Type> *building_tree){
        Node <Type> *new_node = new Node <Type>(input_string[0]);
        building_tree->add_count();
        int pos = find_mid_pos(input_string);
        int length = static_cast <int>(input_string.length());
        if(pos - 2 >= 1){
            new_node->_lchild = build_by_list(input_string.substr(2, pos - 2), building_tree);
        }
        if(length - pos - 2 >= 1){
            new_node->_rchild = build_by_list(input_string.substr(pos + 1, length - pos - 2), building_tree);
        }
        return new_node;
    }
    int find_mid_pos(const string &input_string){
        if(input_string.length() == 1){
            return -1;
        }
        if(input_string.length() == 4){
            return 3;
        }
        for(int i = 0, bracket_number = 0; ; ++i){
            switch(input_string[i]){
                case '(':
                    ++bracket_number;
                    break;
                case ',':
                    if(bracket_number == 1){
                        return i;
                    }
                    break;
                case ')':
                    --bracket_number;
                    break;
                default:
                    break;
            }
        }
    }
};

template <typename Type> class Binary_Tree{
private:
    Node <Type> *_root;
    int _node_count;
    void release_memory(Node <Type> *input_root){
        if(input_root != NULL){
            release_memory(input_root->_lchild);
            release_memory(input_root->_rchild);
            delete input_root;
        }
        return;
    }
public:
    Binary_Tree(){
        _root = NULL;
        _node_count = 0;
    }
    Binary_Tree(const string &input_string){
        if(input_string.empty()){
            _root = NULL;
            _node_count = 0;
            return;
        }
        _root = _root->build_by_list(input_string, this);
    }
    ~Binary_Tree(){
        release_memory(_root);
    }
    void output_list(){
        if(_root == NULL){
            return;
        }
        _root->output_list();
        cout << endl;
        return;
    }
    void add_count(){
        ++_node_count;
        return;
    }
    void traverse_by_layer(){
        if(_root == NULL){
            return;
        }
        for(int i = 1; i <= _node_count; ++i){
            if (i != 1){
                cout << " ";
            }
            cout << access_specific_element(i);
        }
        cout << endl;
    }
    Type access_specific_element(int element_number){
        if(_root == NULL){
            return false;
        }
        if(element_number == 1){
            return _root->_data;
        }
        int layer_number = static_cast <int>(log(element_number)/log(2));
        Stack <int> path(layer_number);
        while(element_number != 1){
            path.push(element_number % 2);
            element_number /= 2;
        }
        Node <Type> *current_node = _root;
        while(layer_number != 0){
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
        return current_node->_data;
    }
};

int main(){
    string input_generalised_list;
    getline(cin, input_generalised_list);
    Binary_Tree <char> binary_tree(input_generalised_list);
    binary_tree.traverse_by_layer();
    return 0;
}
