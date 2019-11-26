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
int _abs(int a) {
    return a < 0 ? -a : a;
}

int _max(int a, int b) {
    return a > b ? a : b;
}

int maxDepth(TreeNode * cur) {
    if (cur==NULL) {
        return 0;
    }
    return 1 + _max(maxDepth(cur->left), maxDepth(cur->right));
}

bool solve(TreeNode * cur) {
    if (cur==NULL) {
        return true;
    }
    if(_abs(maxDepth(cur->left) - maxDepth(cur->right)) > 1) {
        return false;
    }
    return (solve(cur->left) && solve(cur->right));
}

int Solution::isBalanced(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return solve(A);
}
