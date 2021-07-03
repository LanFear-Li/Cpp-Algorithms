//
// Created by LanFear on 2021/1/27.
//

#ifndef DATASTRUCTURE_STRUCTURES_H
#define DATASTRUCTURE_STRUCTURES_H

#include <iomanip>
#include "iostream"

typedef struct node {
    int data = 0;
    node *p = nullptr;
    node *left = nullptr;
    node *right = nullptr;
} Node;

typedef struct tree {
    Node *root = nullptr;
} Tree;

void buildTree(Tree *tree, const int &val);

void inorderTreeWalk(Node *node);

void preorderTreeWalk(Node *node);

void postorderTreeWalk(Node *node);

// search function with recursion
//Node* treeSearch(Node* node, const int &x);

//  search function with iteration
Node *treeSearch(Node *node, const int &x);

Node *treeMinimum(Node *node);

Node *treeMaximum(Node *node);

Node *treeSuccessor(Node *node);

Node *treePredecessor(Node *node);

void treeInsert(Tree *tree, const int &val);

// delete function with if statements
//void treeDelete(Tree* tree, Node* node);

void transplant(Tree *tree, Node *u, Node *v);

// delete function with transplant (child tree)
void treeDelete(Tree *tree, Node *node);

int findNodeHeight(Tree *tree, Node *node);

Node *findLCA(Tree *tree, Node *a, Node *b);

#endif //DATASTRUCTURE_STRUCTURES_H
