//
//  main.cpp
//  chain_list_practice_3
//
//  Created by Michael Hui on 24/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <typename Type> class Node{
public:
    Type _data;
    Node <Type> *_next;
    Node(Type data){
        _data = data;
        _next = NULL;
    }
};

template <typename Type> class Chain_List{
private:
    int _length;
    Node <Type> *_head;
public:
    Chain_List(){
        _head = NULL;
        _length = 0;
    }
    ~Chain_List(){
        if (_head == NULL){
            return;
        }
        Node <Type> *current_node = _head;
        while (current_node != NULL){
            Node <Type> *delete_node = current_node;
            current_node = current_node->_next;
            delete delete_node;
        }
    }
    void insert(Node <Type> *node, int index){
        if (_head == NULL){
            if (_head != 0){
                //cout << "index != 0, insert failed" << endl;
            }
            _head = node;
            node->_next = NULL;
            ++_length;
            //cout << "insert " << node->_data << " success" << endl;
            return;
        }
        if (index == 0){
            node->_next = _head;
            _head = node;
            ++_length;
            //cout << "insert " << node->_data << " success" << endl;
            return;
        }
        int count = 0;
        Node <Type> *current_node = _head;
        while (current_node->_next != NULL && count < index - 1){
            current_node = current_node->_next;
            ++count;
        }
        if (count == index - 1){
            node->_next = current_node->_next;
            current_node->_next = node;
            ++_length;
            cout << "insert " << node->_data << " success" << endl;
        }
        if (node == _head->_next){
            _head = node;
        }
        //cout << "error" << endl;
        return;
    }
    void output(){
        if (_head == NULL){
            //cout << "no node within list" << endl;
            return;
        }
        Node <Type> *current_node = _head;
        while(current_node != NULL){
            if (current_node != _head){
                cout << " ";
            }
            cout << current_node->_data;
            current_node = current_node->_next;
        }
        cout << endl;
        return;
    }
    void reverse(){
        if (_head == NULL){
            return;
        }
        else if (_length == 1){
            return;
        }
        Node <Type> *current_node = _head, *previous_node = NULL, *next_node = current_node->_next;
        while (current_node != NULL){
            next_node = current_node->_next;
            current_node->_next = previous_node;
            previous_node = current_node;
            current_node = next_node;
        }
        _head = previous_node;
        return;
    }
};

int main(){
    Chain_List <char> chain_list;
    int element_number;
    char input;
    cin >> element_number;
    for (int i = 0; i < element_number; ++i){
        cin >> input;
        Node <char> *node = new Node <char> (input);
        chain_list.insert(node, i);
    }
    //chain_list.output();
    chain_list.reverse();
    chain_list.output();
    return 0;
}
