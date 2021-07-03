//
// Created by LanFear on 2021/3/24.
//

#include <iomanip>
#include "AVL.h"

using namespace std;

Node *newNode(const int &key) {
    Node *node = new Node;
    node->val = key;
    node->height = 1;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int getHeight(Node *node) {
    if (node == nullptr) return 0;
    return node->height;
}

int getBalanceFactor(Node *node) {
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(Node *node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

Node *search(Node *root, const int &val) {
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

Node *leftRotation(Node *root) {
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    return temp;
}

Node *rightRotation(Node *root) {
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    return temp;
}

// loop insert
//void insert(Node* &root, const int &val) {
//    Node* node = newNode(val);
//    Node* key = root;
//    Node* y = nullptr;
//    while (key != nullptr) {
//        y = key;
//        if (val < key->val) {
//            key = key->left;
//        } else {
//            key = key->right;
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

// recursion insert
Node *insert(Node *root, const int &val) {
    if (root == nullptr) {
        return newNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
        updateHeight(root);
        if (getBalanceFactor(root) > 1) {
            if (getBalanceFactor(root->left) == 1) {
                return rightRotation(root);
            } else if (getBalanceFactor(root->left) == -1) {
                root->left = leftRotation(root->left);
                return rightRotation(root);
            }
        }
    } else if (val > root->val) {
        root->right = insert(root->right, val);
        updateHeight(root);
        if (getBalanceFactor(root) < -1) {
            if (getBalanceFactor(root->right) == -1) {
                return leftRotation(root);
            } else if (getBalanceFactor(root->right) == 1) {
                root->right = rightRotation(root->right);
                return leftRotation(root);
            }
        }
    }
    return root;
}

Node *minValue(Node *node) {
    Node *current = node;
    while (current->left != nullptr) current = current->left;
    return current;
}

Node *deleteNode(Node *root, int key) {
    if (root == nullptr) {
        return root;
    } else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node *node = root->right;
            free(root);
            return node;
        } else if (root->right == nullptr) {
            Node *node = root->left;
            free(root);
            return node;
        } else {
            Node *node = minValue(root->right);
            root->val = node->val;
            root->right = deleteNode(root->right, node->val);
        }
    }

    updateHeight(root);

    if (getBalanceFactor(root) > 1) {
        if (getBalanceFactor(root->left) >= 0) {
            return rightRotation(root);
        } else {
            root->left = rightRotation(root->left);
            return rightRotation(root);
        }
    } else if (getBalanceFactor(root) < -1) {
        if (getBalanceFactor(root->right) <= 0) {
            return leftRotation(root);
        } else {
            root->right = leftRotation(root->right);
            return leftRotation(root);
        }
    }

    return root;
}

Node *createTree(const int *arr, const int &len) {
    Node *root = nullptr;
    for (int i = 0; i < len; ++i) {
        root = insert(root, arr[i]);
    }
    return root;
}

void inorderTreeWalk(Node *node) {
    if (node != nullptr) {
        inorderTreeWalk(node->left);
        std::cout << std::setw(8) << node->val;
        inorderTreeWalk(node->right);
    }
}

void preorderTreeWalk(Node *node) {
    if (node != nullptr) {
        std::cout << std::setw(8) << node->val;
        preorderTreeWalk(node->left);
        preorderTreeWalk(node->right);
    }
}

void postorderTreeWalk(Node *node) {
    if (node != nullptr) {
        postorderTreeWalk(node->left);
        postorderTreeWalk(node->right);
        std::cout << std::setw(8) << node->val;
    }
}