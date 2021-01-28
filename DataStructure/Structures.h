//
// Created by LanFear on 2021/1/27.
//

#ifndef DATASTRUCTURE_STRUCTURES_H
#define DATASTRUCTURE_STRUCTURES_H

#include <iomanip>
#include "iostream"

typedef struct node {
    int data = 0;
    node* left = nullptr;
    node* right = nullptr;
} Node;

typedef struct tree {
    Node* root = nullptr;
} Tree;

void buildTree(Tree* tree, const int &val) {
    Node* node = new Node;
    node->data = val;
    if (tree->root == nullptr) {
        tree->root = node;
    } else {
        Node* root = tree->root;
        while (root != nullptr) {
            if (val < root->data) {
                if (root->left == nullptr) {
                    root->left = node;
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right == nullptr) {
                    root->right = node;
                    break;
                } else {
                    root = root->right;
                }
            }
        }
    }
}

void inorderTreeWalk(Node* node) {
    if (node != nullptr) {
        inorderTreeWalk(node->left);
        std::cout << std::setw(8) << node->data;
        inorderTreeWalk(node->right);
    }
}

#endif //DATASTRUCTURE_STRUCTURES_H
