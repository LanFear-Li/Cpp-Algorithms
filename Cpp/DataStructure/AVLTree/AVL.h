//
// Created by LanFear on 2021/3/24.
//

#ifndef AVLTREE_AVL_H
#define AVLTREE_AVL_H
#include <iostream>

struct Node {
    int val, height;
    Node* left;
    Node* right;
};

Node* newNode(const int &x);

Node* search(Node* root, const int &val);

Node* insert(Node* root, const int &val);

Node* deleteNode(Node* root, int key);

Node* createTree(const int* arr, const int& len);

void inorderTreeWalk(Node* node);

void preorderTreeWalk(Node* node);

void postorderTreeWalk(Node* node);

#endif //AVLTREE_AVL_H
