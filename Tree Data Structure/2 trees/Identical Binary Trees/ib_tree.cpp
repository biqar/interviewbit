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
bool solve(TreeNode* t1, TreeNode* t2) {
    if(t1==NULL && t2==NULL) return true;
    if((t1==NULL && t2!=NULL) || (t1!=NULL && t2==NULL)) return false;
    if(t1->val != t2->val) {
        return false;
    }
    return solve(t1->left, t2->left) & solve(t1->right, t2->right);
}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return solve(A, B);
}
