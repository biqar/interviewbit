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

void preorder(TreeNode* t, vector<int> &ret) {
    if(t == NULL) return;

    ret.push_back(t->val);
    preorder(t->left, ret);
    preorder(t->right, ret);
}

vector<int> Solution::preorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ret;
    preorder(A, ret);
    return ret;
}
