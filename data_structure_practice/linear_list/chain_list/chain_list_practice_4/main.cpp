//
//  main.cpp
//  chain_list_practice_4
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
    Node <Type> *_prior;
    Node(Type data){
        _data = data;
        _next = NULL;
        _prior = NULL;
    }
};

template <typename Type> class Chain_List{
private:
    Node <Type> *_head;
    int _length;
public:
    Chain_List(){
        _head = NULL;
        _length = 0;
    }
    ~Chain_List(){
        if (_head == NULL){
            cout << "no node within list" << endl;
            return;
        }
        Node <Type> *current_node = _head->_next;
        _head->_next = NULL;
        while (current_node != NULL){
            Node <Type> *delete_node = current_node;
            current_node = current_node->_next;
            delete delete_node;
        }
        return;
    }
    void insert(Node <Type> *node, int index){
        if (_head == NULL){
            if (index != 0){
                cout << "insert " << node->_data << " failed." << endl;
                return;
            }
            _head = node;
            _head->_next = _head;
            _head->_prior = _head;
            ++_length;
            //cout << "insert " << node->_data << " success." << endl;
            return;
        }
        if (index == 0){
            node->_next = _head->_next;
            _head->_next = node;
            node->_prior = _head;
            //cout << "insert " << node->_data << " success." << endl;
        }
        Node <Type> *current_node = _head->_next;
        int count = 0;
        while (current_node != _head && count < index - 1){
            current_node = current_node->_next;
            ++count;
        }
        if (count == index - 1){
            node->_next = current_node->_next;
            current_node->_next->_prior = node;
            node->_prior = current_node;
            current_node->_next = node;
            ++_length;
            //cout << "insert " << node->_data << " success." << endl;
        }
        if (node == _head->_next){
            _head = node;
        }
        return;
    }
    void reverse_output_from_nth_element(const int &index){
        Node <Type> *temp = _head;
        for (int i = 1; i < index; ++i){
            _head = _head->_next;
        }
        reverse_output();
        _head = temp;
        return;
    }
    void reverse_output_from_specific_element(const int &element){
        if (_head == NULL){
            cout << "no node within list." << endl;
            return;
        }
        Node <Type> *current_node = _head, *temp = _head;
        while (current_node->_next->_data != element){
            current_node = current_node->_next;
        }
        _head = current_node;
        reverse_output();
        _head = temp;
        return;
    }
    void reverse_output(){
        if (_head == NULL){
            cout << "no node within list." << endl;
            return;
        }
        Node <Type> *current_node = _head->_next;
        for (int i = 0; i < _length; ++i){
            if (current_node != _head->_next){
                cout << " ";
            }
            cout << current_node->_data;
            current_node = current_node->_prior;
        }
        cout << endl;
        return;
    }
    void output(){
        if (_head == NULL){
            return;
        }
        Node <Type> *current_node = _head->_next;
        for (int i = 0; i < _length; ++i){
            if (current_node != _head->_next){
                cout << " ";
            }
            cout << current_node->_data;
            current_node = current_node->_next;
        }
        cout << endl;
        return;
    }
};

int main(){
    Chain_List <int> chain_list;
    int num_of_elements, temp;
    cin >> num_of_elements;
    for (int i = 0; i < num_of_elements; ++i){
        cin >> temp;
        Node <int> *node = new Node <int>(temp);
        chain_list.insert(node, i);
    }
    cin >> temp;
    chain_list.reverse_output_from_specific_element(temp);
    return 0;
}
