//
//  main.cpp
//  binary_tree_practice_1
//
//  Created by Michael Hui on 2/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

#include<iostream>
using std::cout;
using std::endl;
class Node {
public:
    int data;
    Node *lchild, *rchild;
    Node(int input_data) {
        data = input_data;
        lchild = NULL;
        rchild = NULL;
    }
    ~Node() {
        if (lchild != NULL){
            delete lchild;
        }
        if (rchild != NULL){
            delete rchild;
        }
    }
    void preorder() {
        cout << data << " ";
        if (lchild != NULL){
            lchild->preorder();
        }
        if (rchild != NULL){
            rchild->preorder();
        }
    }
    void inorder() {
        if (lchild != NULL){
            lchild->inorder();
        }
        cout << data << " ";
        if (rchild != NULL){
            rchild->inorder();
        }
    }
    void postorder() {
        if (lchild != NULL){
            lchild->postorder();
        }
        if (rchild != NULL){
            rchild->postorder();
        }
        cout << data << " ";
    }
};
class BinaryTree {
private:
    Node *root;
public:
    BinaryTree() {
        root = NULL;
    }
    ~BinaryTree() {
        delete root;
    }
    void build_demo() {
        root = new Node(4);
        root->lchild = new Node(2);
        root->lchild->lchild = new Node(1);
        root->lchild->rchild = new Node(3);
        root->rchild = new Node(6);
        root->rchild->lchild = new Node(5);
        root->rchild->rchild = new Node(7);
        return;
    }
    void preorder() {
        root->preorder();
        cout << endl;
    }
    void inorder() {
        root->inorder();
        cout << endl;
    }
    void postorder() {
        root->postorder();
        cout << endl;
    }
};
int main() {
    BinaryTree binarytree;
    binarytree.build_demo();
    binarytree.preorder();
    binarytree.inorder();
    binarytree.postorder();
    return 0;
}
