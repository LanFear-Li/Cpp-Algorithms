#include <iostream>
#include "experssionTree.h"

int main() {
    std::cout << "please input a legal bracket expression: " << std::endl;
    std::string str;
    std::cin >> str;
    if (!legalityCheck(str)) {
        std::cout << "illegal expression detected!" << std::endl;
    } else {
        Tree* tree = buildExpressionTree(str);

        std::cout << tree->root->str << '\n';

        inorderTreeWalk(tree->root);
        std::cout << std::endl;

        preorderTreeWalk(tree->root);
        std::cout << std::endl;
        postorderTreeWalk(tree->root);
        std::cout << std::endl;


    }
    return 0;
}
