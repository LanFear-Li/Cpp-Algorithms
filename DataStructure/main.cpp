#include "iostream"
#include "Structures.h"

int main() {
    int arr[5] = {5, 2, 1, 4, 3};
    int len = sizeof arr / sizeof arr[0];
    Tree *tree = new Tree;
    for (size_t i = 0; i < len; ++i ) {
        buildTree(tree, arr[i]);
    }
    inorderTreeWalk(tree->root);
    return 0;
}
