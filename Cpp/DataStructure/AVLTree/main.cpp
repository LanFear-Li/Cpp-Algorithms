#include <iostream>
#include "AVL.h"
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof arr / sizeof arr[0];
    Node* root = createTree(arr, n);
    inorderTreeWalk(root);
    cout << endl;
    preorderTreeWalk(root);
    cout << endl;
    postorderTreeWalk(root);
    cout << endl;

    cout << root->val << " " << root->left->val << " " << root->right->val << endl;
    cout << root->right->left->val << " " << root->right->right->val << endl;
    return 0;
}
