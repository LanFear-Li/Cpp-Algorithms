#include <iostream>
#include "experssionTree.h"

int main() {
    std::cout << "please input a legal bracket expression: " << std::endl;
    std::string str;
    std::cin >> str;
    if (!legalityCheck(str)) {
        std::cout << "illegal expression detected!" << std::endl;
    } else {

    }
    return 0;
}
