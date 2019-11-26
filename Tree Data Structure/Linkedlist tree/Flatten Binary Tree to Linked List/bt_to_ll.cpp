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
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    TreeNode* cur = A;
    while(cur != NULL) {
        if(cur->left != NULL) {
            TreeNode* tmp = cur->left;
            while(tmp->right != NULL) {
                tmp = tmp->right;
            }
            tmp->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
    return A;
}
