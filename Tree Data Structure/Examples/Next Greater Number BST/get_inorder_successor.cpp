//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
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
TreeNode* Solution::getSuccessor(TreeNode* root, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    TreeNode* curr = root;

    while(curr != NULL) {
        if(curr->val < B) curr = curr->right;
        else if(curr->val > B) curr = curr->left;
        else break;
    }

    // inorder successor is in right sub-tree
    if(curr->right != NULL) {
        curr = curr->right;

        while(curr->left != NULL) curr = curr->left;

        return curr;
    }

    // inorder successor is in ancestor
    curr = root;
    TreeNode* succ = NULL;
    while(curr != NULL) {
        if(curr->val < B) curr = curr->right;
        else if(curr->val > B) {
            succ = curr;
            curr = curr->left;
        }
        else break;
    }

    return succ;
}
