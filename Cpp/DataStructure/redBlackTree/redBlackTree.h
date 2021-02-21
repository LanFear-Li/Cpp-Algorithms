//
// Created by LanFear on 2021/1/31.
//

#ifndef REDBLACKTREE_REDBLACKTREE_H
#define REDBLACKTREE_REDBLACKTREE_H

#include <iomanip>
#include "iostream"

/* A red-Black Tree is a binary tree that satisfies the following properties:
 * 1. Every node is either red or black.
 * 2. The root and every leaf are black.
 * 3. If a node is red, then both its children are black.
 * 4. For each node, all simple paths from the node to descendant leaves contain
 *    the same number of black nodes.
 * */

typedef struct node {
    int data = 0;
    int color = 0;
    node* p = nullptr;
    node* left = nullptr;
    node* right = nullptr;
} Node;

typedef struct tree {
    Node* root = nullptr;
} Tree;

void buildTree(Tree* tree, const int &val);

void inorderTreeWalk(Node* node);

void preorderTreeWalk(Node* node);

void postorderTreeWalk(Node* node);

// search function with recursion
//Node* treeSearch(Node* node, const int &x);

//  search function with iteration
Node* treeSearch(Node* node, const int &x);

Node* treeMinimum(Node* node);

Node* treeMaximum(Node* node);

Node* treeSuccessor(Node* node);

Node* treePredecessor(Node* node);

void treeInsert(Tree* tree, const int &val);

// delete function with if statements
//void treeDelete(Tree* tree, Node* node);

void transplant(Tree* tree, Node* u, Node* v);

// delete function with transplant (child tree)
void treeDelete(Tree* tree, Node* node);

#endif //REDBLACKTREE_REDBLACKTREE_H
