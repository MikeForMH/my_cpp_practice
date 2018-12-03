//
//  main.cpp
//  generalised_list_to_binary_tree
//
//  Created by Michael Hui on 3/12/2018.
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
    Node* build_by_list(const string &input_list){
        Node *p = new Node <Type>(input_list[0]);
        int pos = find_mid_pos(input_list);
        int length = static_cast <int>(input_list.length());
        if(pos >= 3){
            p->_lchild = build_by_list(input_list.substr(2, pos - 2));
        }
        if(length - pos - 2 >= 1){
            p->_rchild = build_by_list(input_list.substr(pos + 1, length - pos - 2));
        }
        return p;
    }
    int find_mid_pos(const string &input_list){
        if (input_list.length() == 1){
            return 0;
        }
        if(input_list.length() == 4){
            return 3;
        }
        int bracket_number = 0;
        for(int i = 0; ; ++i){
            switch (input_list[i]) {
                case '(':
                    ++bracket_number;
                    break;
                case ')':
                    --bracket_number;
                    break;
                case ',':
                    if(bracket_number == 1){
                        return i;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    void delete_specific_element(const Type &delete_element){
        if(_lchild != NULL){
            if(_lchild->_data == delete_element){
                delete _lchild;
                _lchild = NULL;
            }
            else{
                _lchild->delete_specific_element(delete_element);
            }
        }
        if(_rchild != NULL){
            if(_rchild->_data == delete_element){
                delete _rchild;
                _rchild = NULL;
            }
            else{
                _rchild->delete_specific_element(delete_element);
            }
        }
        return;
    }
};

template <typename Type> class Binary_Tree{
private:
    Node <Type> *_root;
public:
    Binary_Tree(){
        _root = NULL;
    }
    Binary_Tree(const string &input_list){
        _root = _root->build_by_list(input_list);
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
    void delete_specific_node(const Type &delete_element){
        if(_root->_data == delete_element){
            delete _root;
            _root = NULL;
        }
        else{
            _root->delete_specific_element(delete_element);
        }
        return;
    }
};

int main(){
    string input_string;
    char delete_node;
    getline(cin, input_string);
    if(input_string.empty()){
        return 0;
    }
    cin >> delete_node;
    cin >> input_string >> delete_node;
    Binary_Tree <char> binary_tree(input_string);
    binary_tree.delete_specific_node(delete_node);
    binary_tree.output_tree();
    return 0;
}
