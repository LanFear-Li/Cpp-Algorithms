//
// Created by LanFear on 2021/3/24.
//

#include <iomanip>
#include "AVL.h"
using namespace std;

Node* newNode(const int &x) {
    Node* node = new Node;
    node->val = x;
    node->height = 1;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int getHeight(Node* node) {
    if (node == nullptr) return 0;
    else return node->height;
}

int getBalanceFactor(Node* node) {
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(Node* node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

Node* search(Node* root, const int &val) {
    if (root == nullptr) {
        cout << "tree is empty, search failed!" << endl;
        return nullptr;
    } else {
        if (root->val == val) {
            return root;
        } else if (val < root->val) {
            return search(root->left, val);
        } else {
            return search(root->right, val);
        }
    }
}

void leftRotation(Node* &root) {
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void rightRotation(Node* &root) {
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}


// loop insert
//void insert(Node* &root, const int &val) {
//    Node* node = newNode(val);
//    Node* x = root;
//    Node* y = nullptr;
//    while (x != nullptr) {
//        y = x;
//        if (val < x->val) {
//            x = x->left;
//        } else {
//            x = x->right;
//        }
//    }
//    if (y == nullptr) {
//        root = node;
//    } else if (val < y->val) {
//        y->left = node;
//    } else {
//        y->right = node;
//    }
//}

// recursion loop
void insert(Node* &root, const int &val) {
    if (root == nullptr) {
        root = newNode(val);
        return;
    }
    if (val < root->val) {
        insert(root->left, val);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->left) == 1) {
                rightRotation(root);
            } else if (getBalanceFactor(root->left) == -1) {
                leftRotation(root->left);
                rightRotation(root);
            }
        }
    } else {
        insert(root->right, val);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->right) == -1) {
                leftRotation(root);
            } else if (getBalanceFactor(root->right) == 1) {
                rightRotation(root->right);
                leftRotation(root);
            }
        }
    }
}

Node* createTree(const int* arr, const int& len) {
    Node* root = nullptr;
    for (int i = 0; i < len; ++i) insert(root, arr[i]);
    return root;
}

void inorderTreeWalk(Node* node) {
    if (node != nullptr) {
        inorderTreeWalk(node->left);
        std::cout << std::setw(8) << node->val;
        inorderTreeWalk(node->right);
    }
}

void preorderTreeWalk(Node* node) {
    if (node != nullptr) {
        std::cout << std::setw(8) << node->val;
        preorderTreeWalk(node->left);
        preorderTreeWalk(node->right);
    }
}

void postorderTreeWalk(Node* node) {
    if (node != nullptr) {
        postorderTreeWalk(node->left);
        postorderTreeWalk(node->right);
        std::cout << std::setw(8) << node->val;
    }
}