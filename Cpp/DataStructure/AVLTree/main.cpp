#include <iostream>
#include "AVL.h"

using namespace std;

int main() {
    Node *root = nullptr;

    /* Constructing tree given in the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */

    printf("Preorder traversal of the constructed AVL "
           "tree is \n");
    preorderTreeWalk(root);

    root = deleteNode(root, 10);

    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */

    printf("\nPreorder traversal after deletion of 10 \n");
    preorderTreeWalk(root);

    return 0;
}
