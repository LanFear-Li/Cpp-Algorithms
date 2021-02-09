//
// Created by LanFear on 2021/1/31.
//

#include "expressionTree.h"

//bool checkLegality(const std::string &x) {
//    int check = 0;
//    for (auto i : x) {
//        if (i == '(') {
//            check += 1;
//        } else if (i == ')') {
//            check -= 1;
//        }
//        if (check < 0) {
//            return false;
//        }
//    }
//    return check == 0;
//}

//std::string modifyExpression(std::string x) {
//    std::string str = x;
//    for (int i = 1; i < str.size(); ++i) {
//        if (x[i] == '-' && (x[i - 1] < '0' || x[i - 1] > '9')) {
//            str = str.insert(i, "0");
//        }
//    }
//    return str;
//}

std::string generateLeftSubstring(const std::string& x, const int& place) {
    std::string str;
    bool checkPossibility = true;
    for (size_t i = 0; i < place; ++i) {
        if (x[i] < '0' || x[i] > '9') {
            checkPossibility = false;
            break;
        }
    }
    if (checkPossibility) {
        str = x.substr(0, place);
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
    bool checkPossibility = true;
    for (size_t i = place + 1; i < x.size(); ++i) {
        if (x[i] < '0' || x[i] > '9') {
            checkPossibility = false;
            break;
        }
    }
    if (checkPossibility) {
        str = x.substr(place + 1);
        return str;
    } else {
        str = x.substr(place + 1);
        str = str.substr(1);
        str = str.substr(0, x.size() - place - 3);
        return str;
    }
}

bool isNumber(std::string& x) {
    for (char i : x) {
        if(i < '0' || i > '9') {
            return false;
        }
    }
    return true;
}

Node* buildExpressionTree(std::string& x) {
    Node* node = new Node;
    int count = 0;
    if (isNumber(x)) {
        for (size_t i = 0; i < x.size(); ++i) {
            node->str[i] = x[i];
            node->order = x.size();
        }
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
                    node->str[0] = x[i];
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

int convertArrayToInt(const char* x, const int& order) {
    int res = 0, cur = 1;
    for (int i = order - 1; i >= 0; --i) {
        res += cur * (x[i] - '0');
        cur *= 10;
    }
    return res;
}

int calculation(Node* root) {
    if (root->left == nullptr && root->right == nullptr) {
        return convertArrayToInt(root->str, root->order);
    } else {
        switch (root->str[0]) {
            case '+':
                return calculation(root->left) + calculation(root->right);
            case '-':
                return calculation(root->left) - calculation(root->right);
            case '*':
                return calculation(root->left) * calculation(root->right);
            case '/':
                return calculation(root->left) / calculation(root->right);
            default:
                return 0;
        }
    }
}

// ******************************************************************************