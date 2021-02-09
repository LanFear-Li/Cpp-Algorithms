//
// Created by LanFear on 2021/1/31.
//

/* Set several purposes as follows:
 * * check the Arithmetic expression whether is legal.
 * 1 store the bracket expression.
 * 2 calculate and output the answer of the expression.
 * */

#ifndef BRACKETexpression_expressionTREE_H
#define BRACKETexpression_expressionTREE_H

#include <iostream>
#include "iomanip"

typedef struct node {
    char str = '0';
    node* left = nullptr;
    node* right = nullptr;
} Node;

typedef struct tree {
    Node* root = nullptr;
} Tree;

bool checkLegality(const std::string &x);

Node* buildExpressionTree(std::string &x);

int calculation(Node* root);

#endif //BRACKETexpression_expressionTREE_H
