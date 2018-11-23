//
//  main.cpp
//  chain_list_practice_2
//
//  Created by Michael Hui on 23/11/2018.
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
    Node(const Type &data){
        _data = data;
        _next = NULL;
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
        Node <Type> *current_node = _head;
        while(current_node != NULL){
            Node <Type> *delete_note = current_node;
            current_node = current_node->_next;
            delete delete_note;
            --_length;
        }
    }
    void insert(Node <Type> *node, int index){
        if (_head == NULL){
            if (index != 0){
                return;
            }
            _head = node;
            ++_length;
            //testing_output();
            return;
        }
        if (index == 0){
            node->_next = _head;
            _head = node;
            ++_length;
            //testing_output();
            return;
        }
        Node <Type> *current_node = _head;
        int count = 0;
        while (current_node->_next != NULL && count < index - 1){
            current_node = current_node->_next;
            ++count;
        }
        if (count == index - 1){
            //if (current_node->_next == NULL){
            //    current_node->_next = node;
            //    ++_length;
            //    return;
            //}
            node->_next = current_node->_next;
            current_node->_next = node;
            ++_length;
            //testing_output();
            return;
        }
        cout << "error" << endl;
        return;
    }
    void remove_node(int index){
        if (_head == NULL){
            //testing_output();
            return;
        }
        Node <Type> *current_node = _head;
        int count = 0;
        if (index == 0){
            _head = _head->_next;
            delete current_node;
            --_length;
            return;
            //testing_output();
        }
        while (current_node->_next != NULL && count < index - 1){
            current_node = current_node->_next;
            ++count;
        }
        if (count == index - 1 && current_node->_next != NULL){
            Node <Type> *delete_node = current_node->_next;
            current_node->_next = delete_node->_next;
            delete delete_node;
            --_length;
            return;
            //testing_output();
        }
        cout << "error" << endl;
        return;
    }
    void print_node(const int &index){
        if (_head == NULL){
            return;
        }
        Node <Type> *current_node = _head;
        for (int i = 0; i < index; ++i){
            current_node = current_node->_next;
        }
        cout << current_node->_data << endl;
        return;
    }
    int get_length(){
        return _length;
    }
    void testing_output(){
        Node <Type> *current_node = _head;
        if (_length == 0){
            return;
        }
        if (_length == 1){
            cout << current_node->_data << endl;
        }
        while (current_node != NULL){
            if (current_node != _head){
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
    int n, m, num;
    cin >> n;
    for (int i = 0; i < n; ++i){
        Node <int> *node = new Node <int>(i + 1);
        chain_list.insert(node, i);
    }
    //chain_list.testing_output();
    
    
    cin >> m;
    for (; m > 0; --m){
        cin >> num;
        chain_list.remove_node(num - 1);
    }
    
    
    /*
    cin >> m;
    cin >> num;
    chain_list.remove_node(num);
    cin >> num;
    chain_list.remove_node(num);
     */
    
    //cout << "length : " << chain_list.get_length() << endl;
    chain_list.print_node(chain_list.get_length()/2);
    return 0;
}
