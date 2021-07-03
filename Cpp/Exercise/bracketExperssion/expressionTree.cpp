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

std::string generateLeftSubstring(const std::string &x, const int &place) {
    std::string str;
    bool checkPossibility = true;
    for (size_t i = 0; i < place; ++i) {
        if (i == 0 && x[i] == '-') {
            continue;
        } else if (x[i] < '0' || x[i] > '9') {
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

std::string generateRightSubstring(const std::string &x, const int &place) {
    std::string str;
    bool checkPossibility = true;
    for (size_t i = place + 1; i < x.size(); ++i) {
        if (i == 0 && x[i] == '-') {
            continue;
        } else if (x[i] < '0' || x[i] > '9') {
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

bool isNumber(std::string &x) {
    for (size_t i = 0; i < x.size(); ++i) {
        if (i == 0 && x[i] == '-') {
            continue;
        } else if (x[i] < '0' || x[i] > '9') {
            return false;
        }
    }
    return true;
}

Node *buildExpressionTree(std::string x) {
    Node *node = new Node;
    int count = 0;
    if (isNumber(x)) {
        if (x[0] == '-') {
            for (size_t i = 1; i < x.size(); ++i) {
                node->str[i - 1] = x[i];
            }
            node->left = nullptr;
            node->right = nullptr;
            node->order = x.size() - 1;
            node->isNegative = true;
        } else {
            for (size_t i = 0; i < x.size(); ++i) {
                node->str[i] = x[i];
            }
            node->left = nullptr;
            node->right = nullptr;
            node->order = x.size();
        }
    } else {
        for (size_t i = 0; i < x.size(); ++i) {
            if (x[i] == '(') {
                count += 1;
            } else if (x[i] == ')') {
                count -= 1;
            } else if (i != 0 && x[i] < '0' || x[i] > '9') {
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

int convertArrayToInt(Node *root) {
    int res = 0, cur = 1;
    for (int i = root->order - 1; i >= 0; --i) {
        res += cur * (root->str[i] - '0');
        cur *= 10;
    }
    if (root->isNegative) {
        res *= -1;
    }
    return res;
}

int calculation(Node *root) {
    if (root->left == nullptr && root->right == nullptr) {
        return convertArrayToInt(root);
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

std::string format_string(std::string str) {
    std::string s = str;
    if (str[0] == '(' && str[str.length() - 1] == ')') {
        s = str.substr(1);
        s = s.substr(0, s.length() - 1);
    }
    return s;
}

// ******************************************************************************