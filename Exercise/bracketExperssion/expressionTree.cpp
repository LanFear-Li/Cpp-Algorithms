//
// Created by LanFear on 2021/1/31.
//

#include "expressionTree.h"

bool checkLegality(const std::string &x) {
    int check = 0;
    for (auto i : x) {
        if (i == '(') {
            check += 1;
        } else if (i == ')') {
            check -= 1;
        }
        if (check < 0) {
            return false;
        }
    }
    return check == 0;
}

std::string generateLeftSubstring(const std::string& x, const int& place) {
    std::string str;
    if (x.size() == 3) {
        str = x.substr(0, 1);
        return str;
    } else {
        str = x.substr(0, place);
        str = str.substr(1);
        str = str.substr(0, place - 2);
        return str;
    }
}

std::string generateRightSubstring(const std::string& x, const int& place) {
    std::string str;
    if (x.size() == 3) {
        str = x.substr(place + 1);
        return str;
    } else {
        str = x.substr(place + 1);
        str = str.substr(0, place - 1);
        str = str.substr(1);
        return str;
    }
}

Node* buildExpressionTree(std::string &x) {
    Node* node = new Node;
    int count = 0;
    if (x.size() == 1) {
        node->str = x[0];
        node->left = nullptr;
        node->right = nullptr;
    } else {
        for (size_t i = 0; i < x.size(); ++i) {
            if (x[i] == '(') {
                count += 1;
            } else if (x[i] == ')') {
                count -= 1;
            } else if (x[i] < '0' || x[i] > '9') {
                if (count == 0) {
                    node->str = x[i];
                    std::string leftString = generateLeftSubstring(x, i);
                    std::string rightString = generateRightSubstring(x, i);
                    node->left = buildExpressionTree(leftString);
                    node->right = buildExpressionTree(rightString);
                    break;
                }
            }
        }
    } 
    return node;
}

int calculation(Node* root) {
    if (root->left == nullptr && root->right == nullptr) {
        return root->str - '0';
    } else {
        switch (root->str) {
            case '+':
                return calculation(root->left) + calculation(root->right);
            case '-':
                return calculation(root->left) - calculation(root->right);
            case '*':
                return calculation(root->left) * calculation(root->right);
            case '/':
                return calculation(root->left) / calculation(root->right);
        }
    }
}

// ******************************************************************************