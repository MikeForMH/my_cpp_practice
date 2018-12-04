//
//  main.cpp
//  3_tuple_to_binary_tree
//
//  Created by Michael Hui on 4/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

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
            if(_lchild != NULL){
                _lchild->output_list();
            }
            if(_rchild != NULL){
                cout << ',';
                _rchild->output_list();
            }
            cout << ')';
        }
        return;
    }
    void find_specific_node(const char &input_data, Node <Type> **ptr_to_current_node){
        if(_data == input_data){
            *ptr_to_current_node = this;
            return;
        }
        if(this->_lchild != NULL){
            this->_lchild->find_specific_node(input_data, ptr_to_current_node);
        }
        if(this->_rchild != NULL){
            this->_rchild->find_specific_node(input_data, ptr_to_current_node);
        }
        return;
    }
};

template <typename Type> class Binary_Tree{
private:
    Node <Type> *_root;
    int _count;
    void free_memory(Node <Type> *input_node){
        if(input_node != NULL){
            free_memory(input_node->_lchild);
            free_memory(input_node->_rchild);
            delete input_node;
        }
        return;
    }
public:
    Binary_Tree(){
        _root = NULL;
        //_count = 0;
    }
    ~Binary_Tree(){
        free_memory(_root);
    }
    void output_list(){
        if(_root != NULL){
            _root->output_list();
            cout << endl;
        }
        return;
    }
    bool insert_by_tuple(const string &input_str){
        if(input_str[0] == '^'){
            _root = new Node <Type>(input_str[1]);
            return true;
        }
        Node <Type> *current_node = NULL;
        Node <Type> **ptr_to_current_node = &current_node;
        char temp = input_str[0];
        _root->find_specific_node(temp, ptr_to_current_node);
        temp = input_str[1];
        switch(input_str[2]){
            case 'L':
                current_node->_lchild = new Node <Type>(temp);
                return true;
            case 'R':
                current_node->_rchild = new Node <Type>(temp);
                return true;
        }
        cout << "error" << endl;
        return false;
    }
};

int main(){
    Binary_Tree <char> binary_tree;
    string input_data;
    cin >> input_data;
    while (input_data[1] != '^'){
        binary_tree.insert_by_tuple(input_data);
        cin >> input_data;
    }
    binary_tree.output_list();
    return 0;
}
