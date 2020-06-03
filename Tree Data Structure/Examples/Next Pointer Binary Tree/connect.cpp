//
// Created by Islam, Abdullah Al Raqibul on 6/2/20.
//

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

void inorder(TreeLinkNode* curr) {
    if(curr->left == NULL|| curr->right == NULL) return;

    curr->left->next = curr->right;
    curr->right->next = curr->next != NULL ? curr->next->left : NULL;

    inorder(curr->left);
    inorder(curr->right);
}

void Solution::connect(TreeLinkNode* A) {
    //A->next = NULL;
    return inorder(A);
}
