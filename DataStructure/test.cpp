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
    std::cout << std::endl;
    preorderTreeWalk(tree->root);
    std::cout << std::endl;
    postorderTreeWalk(tree->root);
    std::cout << std::endl;

    std::cout << "the element you searched is: " << treeSearch(tree->root, 5)->data << std::endl;
    std::cout << "the minimum element is: " << treeMinimum(tree->root)->data << std::endl;
    std::cout << "the maximum element is: " << treeMaximum(tree->root)->data << std::endl;
    std::cout << "the successor of 4 is: " << treeSuccessor(tree->root->left->right)->data << std::endl;
    std::cout << "the predecessor of 4 is: " << treePredecessor(tree->root->left->right)->data << std::endl;
    return 0;
}
