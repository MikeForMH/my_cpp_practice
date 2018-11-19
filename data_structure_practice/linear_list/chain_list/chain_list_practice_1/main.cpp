//
//  main.cpp
//  chain_list_practice_1
//
//  Created by Michael Hui on 20/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

#include <iostream>
using namespace std;

template <typename Type> class Node {
public:
    Type data;
    Node<Type> *next;
    Node(const Type &_data) {
        data = _data;
        next = NULL;
    }
};
template <typename Type> class LinkedList {
private:
    Node<Type> *head;
public:
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        Node<Type> *current_node = head;
        while (current_node != NULL) {
            Node<Type> *delete_node = current_node;
            current_node = current_node->next;
            delete delete_node;
        }
    }
    bool insert(Node<Type> *node, int index) {
        if (head == NULL) {
            if (index != 0) {
                return false;
            }
            head = node;
            return true;
        }
        if (index == 0) {
            node->next = head;
            head = node;
            return true;
        }
        Node<Type> *current_node = head;
        int count = 0;
        while (current_node->next != NULL && count < index - 1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1) {
            node->next = current_node->next;
            current_node->next = node;
            return true;
        }
        return false;
    }
    void output() {
        if (head == NULL) {
            return;
        }
        Node<Type> *current_node = head;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
    void delete_node(int index) {
        if (head == NULL){
            cout << "failed" << endl;
            return;
        }
        Node <Type> *current_node = head;
        if (index == 0){
            head = head->next;
            delete current_node;
            cout << "success" << endl;
            return;
        }
        int count = 0;
        while (current_node->next != NULL && count < index - 1){
            current_node = current_node->next;
            ++count;
        }
        if (count == index - 1 && current_node->next != NULL){
            Node <Type> *delete_node = current_node->next;
            current_node->next = delete_node->next;
            delete delete_node;
            cout << "success" << endl;
            return;
        }
        cout << "failed" << endl;
        return;
    }
    void reverse() {
        if (head == NULL){
            return;
        }
        Node <Type> *current_node = head->next;
        if (current_node == NULL){
            return;
        }
        Node <Type> *temp_node = current_node->next;
        head->next = NULL;
        current_node->next = head;
        head = current_node;
        current_node = temp_node;
        while (current_node != NULL){
            temp_node = current_node->next;
            current_node->next = head;
            head = current_node;
            current_node = temp_node;
        }
        return;
    }
};
int main() {
    LinkedList<int> linkedlist;
    int operations, flag, index, value;
    Node <int> *node;
    cin >> operations;
    for(; operations > 0; --operations){
        cin >> flag;
        switch(flag){
            case 1:
                cin >> index >> value;
                node = new Node <int> (value);
                if(linkedlist.insert(node, index)){
                    cout << "success" << endl;
                }
                else {
                    cout << "failed" << endl;
                }
                break;
            case 2:
                linkedlist.output();
                break;
            case 3:
                cin >> index;
                linkedlist.delete_node(index);
                break;
            case 4:
                linkedlist.reverse();
                break;
        }
    }
    return 0;
}
