//
// Created by LanFear on 2021/1/31.
//

/* Set several purposes as follows:
 * 1 check the bracket expression whether is legal.
 * 2 output three kinds of tree walk of the expression.
 * 3 output the answer of the expression.
 * */

#ifndef BRACKETEXPERSSION_EXPERSSIONTREE_H
#define BRACKETEXPERSSION_EXPERSSIONTREE_H

#include <iostream>
#include "iomanip"

bool legalityCheck(const std::string &x);

typedef struct node {
    int data = 0;
    char str = '0';
    node* p = nullptr;
    node* left = nullptr;
    node* right = nullptr;
} Node;

typedef struct tree {
    Node* root = nullptr;
} Tree;

void buildTree(Tree* tree, const int &val, const char &str);

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

#endif //BRACKETEXPERSSION_EXPERSSIONTREE_H
