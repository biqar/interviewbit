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
int solve(TreeNode* cur, int v1, int v2) {
    if(cur == NULL) return -1;
    if(cur->val == v1 || cur->val == v2) return cur->val;

    int l = solve(cur->left, v1, v2);
    int r = solve(cur->right, v1, v2);

    //cout << "L = " << l << " R = " << r << endl;

    if(l!=-1 && r!=-1) return cur->val;
    return l == -1 ? r : l;
}

bool found(TreeNode* cur, int val) {
    if(cur == NULL) return false;
    if(cur->val == val) return true;

    return (found(cur->left, val) || found(cur->right, val));
}

int Solution::lca(TreeNode* A, int val1, int val2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(!found(A, val1) || !found(A, val2)) return -1;
    return solve(A, val1, val2);
}
