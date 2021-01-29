//
// Created by LanFear on 2021/1/27.
//

#ifndef DATASTRUCTURE_STRUCTURES_H
#define DATASTRUCTURE_STRUCTURES_H

#include <iomanip>
#include "iostream"

typedef struct node {
    int data = 0;
    node* p = nullptr;
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
                    node->p = root;
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right == nullptr) {
                    root->right = node;
                    node->p = root;
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

void preorderTreeWalk(Node* node) {
    if (node != nullptr) {
        std::cout << std::setw(8) << node->data;
        inorderTreeWalk(node->left);
        inorderTreeWalk(node->right);
    }
}

void postorderTreeWalk(Node* node) {
    if (node != nullptr) {
        inorderTreeWalk(node->left);
        inorderTreeWalk(node->right);
        std::cout << std::setw(8) << node->data;
    }
}

// search function with recursion
//Node* treeSearch(Node* node, const int &x) {
//    if (node == nullptr) {
//        Node* tNode = new Node;
//        std::cout << "Couldn't find this element!" << std::endl;
//        return tNode;
//    } else if (node->data == x) {
//        return node;
//    } else {
//        if (x < node->data) {
//            return treeSearch(node->left, x);
//        } else {
//            return treeSearch(node->right, x);
//        }
//    }
//}

//  search function with iteration
Node* treeSearch(Node* node, const int &x) {
    while (node != nullptr && node->data != x) {
        if (x < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    if (node == nullptr) {
        Node* tNode = new Node;
        std::cout << "Couldn't find this element!" << std::endl;
        return tNode;
    } else {
        return node;
    }
}

Node* treeMinimum(Node* node) {
    if (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* treeMaximum(Node* node) {
    if (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

Node* treeSuccessor(Node* node) {
    if (node->right != nullptr) {
        return treeMinimum(node->right);
    } else {
        Node* pNode = node->p;
        while (pNode != nullptr && node == pNode->right) {
            node = pNode;
            pNode = pNode->p;
        }
        if (node->p != nullptr) {
            return pNode;
        } else {
            std::cout << "no successor exist!" << std::endl;
            Node* tNode = new Node;
            return tNode;
        }
    }
}

Node* treePredecessor(Node* node) {
    if (node->left != nullptr) {
        return treeMaximum(node->left);
    } else {
        Node* pNode = node->p;
        while (pNode != nullptr && node == pNode->left) {
            node = pNode;
            pNode = pNode->p;
        }
        if (node->p != nullptr) {
            return pNode;
        } else {
            std::cout << "no successor exist!" << std::endl;
            Node* tNode = new Node;
            return tNode;
        }
    }
}

void treeInsert(const int &val) {

}

#endif //DATASTRUCTURE_STRUCTURES_H
