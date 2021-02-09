#include <iostream>
#include "expressionTree.h"

int main() {
    std::cout << "please input a legal bracket expression: " << std::endl;
    std::string str;
    std::cin >> str;

    Node* root = buildExpressionTree(str);
    int res = calculation(root);
    std::cout << res << std::endl;
    return 0;
}
