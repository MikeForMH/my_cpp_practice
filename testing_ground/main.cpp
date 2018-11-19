//
//  main.cpp
//  testing_ground
//
//  Created by Michael Hui on 16/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

#include <iostream>
using namespace std;

template <typename Type> class Node {
public:
    Node(int value){
        data = value;
        next = NULL;
    }
    Type data;
    Node <Type> *next;
};
template <typename Type> class LinkedList {
private:
    Node <Type> *head;
public:
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        Node <Type> *delete_node;
        Node <Type> *current_node = head;
        while (current_node != NULL){
            delete_node = current_node;
            current_node = current_node->next;
            delete delete_node;
        }
    }
    void insert(int index, int value) {
        if (head == NULL){
            if (index != 0){
                cout << "failed" << endl;
                return;
            }
            head = new Node <int>(value);
            cout << "success" << endl;
            return;
        }
        int count = 0;
        Node <int> *current_node = head;
        while (current_node != NULL && count < index - 1){
            current_node = current_node->next;
            ++count;
        }
        if (count == index - 1){
            Node <int> *insert_node = new Node <int> (value);
            insert_node->next = current_node->next;
            current_node->next = insert_node;
            cout << "success" << endl;
            return;
        }
        cout << "failed" << endl;
        return;
    }
    void output() {
        Node <Type> *current_node = head;
        while (current_node != NULL){
            if (current_node != head){
                cout << " ";
            }
            cout << current_node->value;
            current_node = current_node->next;
        }
        cout << endl;
        return;
    }
};
int main() {
    LinkedList<int> linkedlist;
    int n;
    cin >> n;
    int index, value;
    for (; n > 0; --n){
        cin >> index >> value;
        linkedlist.insert(index, value);
    }
    linkedlist.output();
    return 0;
}
