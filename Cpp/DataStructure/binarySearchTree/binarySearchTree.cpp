//
// Created by LanFear on 2021/1/31.
//

#include <iomanip>
#include "iostream"
#include "binarySearchTree.h"

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
        preorderTreeWalk(node->left);
        preorderTreeWalk(node->right);
    }
}

void postorderTreeWalk(Node* node) {
    if (node != nullptr) {
        postorderTreeWalk(node->left);
        postorderTreeWalk(node->right);
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

void treeInsert(Tree* tree, const int &val) {
    Node* node = new Node;
    Node* x = tree->root;
    Node* y = nullptr;
    node->data = val;
    while (x != nullptr) {
        y = x;
        if (val < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    node->p = y;
    if (y == nullptr) {
        tree->root = node;
    } else if (val < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }
}

// delete function with if statements
//void treeDelete(Tree* tree, Node* node) {
//    if (node->left == nullptr && node->right == nullptr) {
//        if (node->p == nullptr) {
//            node = nullptr;
//            std::cout << "root node has been deleted! " << std::endl;
//        } else if (node->p->left != nullptr && node->p->left == node) {
//            node->p->left = nullptr;
//        } else {
//            node->p->right = nullptr;
//        }
//    } else if (node->left != nullptr && node->right != nullptr) {
//        Node* keyNode = treeSuccessor(node);
//        if (keyNode->p->left == keyNode) {
//            keyNode->p->left = nullptr;
//        } else {
//            keyNode->p->right = nullptr;
//        }
//        if (node->p == nullptr) {
//            keyNode->p = nullptr;
//        } else if (node->p->left == node) {
//            keyNode->p = node->p;
//            node->p->left = keyNode;
//        } else {
//            keyNode->p = node->p;
//            node->p->right = keyNode;
//        }
//        keyNode->left = node->left;
//        node->left->p = keyNode;
//        keyNode->right = node->right;
//    } else {
//        if (node->left != nullptr) {
//            node->left->p = node->p;
//            if (node->p != nullptr) {
//                if (node->p->left == node) {
//                    node->p->left = node->left;
//                } else {
//                    node->p->right = node->left;
//                }
//            }
//        } else {
//            node->right->p = node->p;
//            if (node->p != nullptr) {
//                if (node->p->left == node) {
//                    node->p->left = node->right;
//                } else {
//                    node->p->right = node->right;
//                }
//            }
//        }
//    }
//    free(node);
//}

void transplant(Tree* tree, Node* u, Node* v) {
    if (u->p == nullptr) {
        tree->root = v;
    } else if (u->p->left != nullptr && u->p->left == u) {
        u->p->left = v;
    } else {
        u->p->right = v;
    }
    if (v != nullptr) {
        v->p = u->p;
    }
}

// delete function with transplant (child tree)
void treeDelete(Tree* tree, Node* node) {
    if (node->left == nullptr) {
        transplant(tree, node, node->right);
    } else if (node->right == nullptr) {
        transplant(tree, node, node->left);
    } else {
        Node* tNode = treeMinimum(node->right);
        if (tNode->p != node) {
            transplant(tree, tNode, tNode->right);
            tNode->right = node->right;
            tNode->right->p = tNode;
        }
        transplant(tree, node, tNode);
        tNode->left = node->left;
        tNode->left->p = tNode;
    }
}