//
//  main.cpp
//  mirror_tree
//
//  Created by Michael Hui on 2/12/2018.
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
    void post_order(){
        if(_lchild != NULL){
            _lchild->post_order();
        }
        if(_rchild != NULL){
            _rchild->post_order();
        }
        cout << _data;
    }
    Node* build(const string &pre_str, const string &in_str, int length){
        Node* p = new Node <char>(pre_str[0]);
        int pos = static_cast <int>(in_str.find(pre_str[0]));
        if (pos > 0){
            p->_lchild = build(pre_str.substr(1, pos), in_str.substr(0, pos), pos);
        }
        if (length - pos - 1 > 0){
            p->_rchild = build(pre_str.substr(pos + 1), in_str.substr(pos + 1), length - pos - 1);
        }
        return p;
    }
    Node* build_mirror(const string &pre_str, const string &in_str, int length){
        Node *p = new Node <char>(pre_str[0]);
        int pos = static_cast <int>(in_str.find(pre_str[0]));
        if (pos > 0){
            p->_rchild = build_mirror(pre_str.substr(1, pos), in_str.substr(0, pos), pos);
        }
        if (length - pos - 1 > 0){
            p->_lchild = build_mirror(pre_str.substr(pos + 1), in_str.substr(pos + 1), length - pos - 1);
        }
        return p;
    }
};

template <typename Type> class BinaryTree{
private:
    Node <Type> *_root;
public:
    BinaryTree(){
        _root = NULL;
    }
    ~BinaryTree(){
        delete _root;
    }
    BinaryTree(const string &pre_str, const string &in_str, int length){
        _root = _root->build(pre_str, in_str, length);
    }
    void build_mirror_tree(const string &pre_str, const string &in_str, int length){
        _root = _root->build_mirror(pre_str, in_str, length);
    }
    void post_order(){
        _root->post_order();
        cout << endl;
    }
};

int main(){
    string pre_str, in_str;
    cin >> pre_str >> in_str;
    BinaryTree <char> binarytree(pre_str, in_str, static_cast <int>(in_str.length()));
    binarytree.post_order();
    BinaryTree <char> mirror_tree;
    mirror_tree.build_mirror_tree(pre_str, in_str, static_cast <int>(in_str.length()));
    mirror_tree.post_order();
    return 0;
}
