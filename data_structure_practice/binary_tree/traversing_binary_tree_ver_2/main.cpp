//
//  main.cpp
//  traversing_binary_tree_ver_2
//
//  Created by Michael Hui on 20/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <queue>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::string;

class Binary_Tree;

class Node{
private:
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
public:
    char _data;
    Node *_lchild, *_rchild;
    Node(const char &input_data){
        _data = input_data;
        _lchild = NULL;
        _rchild = NULL;
    }
    ~Node(){
        return;
    }
    Node* build_by_list(const string &input_string){
        Node *new_node = new Node(input_string[0]);
        int pos = find_mid_pos(input_string);
        int length = static_cast <int>(input_string.length());
        if(pos - 2 >= 1){
            new_node->_lchild = build_by_list(input_string.substr(2, pos - 2));
        }
        if(length - pos - 2 >= 1){
            new_node->_rchild = build_by_list(input_string.substr(pos + 1, length - pos - 2));
        }
        return new_node;
    }
};

class Binary_Tree{
private:
    Node *_root;
    void release_memory(Node *input_node){
        if(input_node != NULL){
            if(input_node->_lchild != NULL){
                release_memory(input_node->_lchild);
            }
            if(input_node->_rchild != NULL){
                release_memory(input_node->_rchild);
            }
            delete input_node;
        }
        return;
    }
public:
    Binary_Tree(const string &input_list){
        if(input_list.empty()){
            _root = NULL;
            return;
        }
        _root = _root->build_by_list(input_list);
        return;
    }
    ~Binary_Tree(){
        release_memory(_root);
    }
    void traverse_by_layer(){
        queue <Node*> traversing_queue;
        queue <char> result;
        if(_root){
            traversing_queue.push(_root);
        }
        while(!traversing_queue.empty()){
            Node *temp = traversing_queue.front();
            result.push(temp->_data);
            traversing_queue.pop();
            if(temp->_lchild){
                traversing_queue.push(temp->_lchild);
            }
            if(temp->_rchild){
                traversing_queue.push(temp->_rchild);
            }
        }
        for(size_t i = 0, size = result.size(); i < size; ++i){
            if(i != 0){
                cout << " ";
            }
            cout << result.front();
            result.pop();
        }
        cout << endl;
        return;
    }
};

int main(){
    string input_generalised_list;
    getline(cin, input_generalised_list);
    Binary_Tree binary_tree(input_generalised_list);
    binary_tree.traverse_by_layer();
    return 0;
}
