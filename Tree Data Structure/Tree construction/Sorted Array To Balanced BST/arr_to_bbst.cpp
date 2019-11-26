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
TreeNode* solve(const vector<int> &A, int l, int r) {
    if(l > r) return NULL;

    int mid = l + (r - l) / 2;
    TreeNode* t = new TreeNode(A[mid]);
    t->left = solve(A, l, mid-1);
    t->right = solve(A, mid+1, r);
    return t;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int sz = A.size();
    if(sz == 0) return NULL;
    return solve(A, 0, sz-1);
}
