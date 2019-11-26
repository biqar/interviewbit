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
int _max(int a, int b) {
    return a > b ? a : b;
}

int solve(TreeNode* cur) {
    if(cur == NULL) return 0;

    return _max(solve(cur->left), solve(cur->right)) + 1;
}

int Solution::maxDepth(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return solve(A);
}
