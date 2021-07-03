#include <iostream>
#include "expressionTree.h"

int main() {
    std::cout << "please input a legal bracket expression: " << std::endl;
    std::string str;
    std::cin >> str;
    Node* root = buildExpressionTree(format_string(str));
    int res = calculation(root);
    std::cout << "the result is: " << res << std::endl;
    return 0;
}
