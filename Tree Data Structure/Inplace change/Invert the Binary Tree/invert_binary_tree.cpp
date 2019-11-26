//
// Created by Islam, Abdullah Al Raqibul on 11/26/19.
//

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void traverse(TreeNode* cur) {
    if(cur==NULL) return;
    TreeNode* tmp;
    tmp = cur->left;
    cur->left = cur->right;
    cur->right = tmp;

    traverse(cur->left);
    traverse(cur->right);
}

TreeNode* Solution::invertTree(TreeNode* root) {
    traverse(root);
    return root;
}
