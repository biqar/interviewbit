//
// Created by Islam, Abdullah Al Raqibul on 5/22/20.
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

int recur(TreeNode* A, int &double_path) {
    if(A == NULL) return 0;

    int l = recur(A->left, double_path);
    int r = recur(A->right, double_path);

    int single_path = _max(A->val, _max(r, l) + A->val);
    double_path = _max(_max(single_path, r + l + A->val), double_path);

    return single_path;
}

int Solution::maxPathSum(TreeNode* A) {
    int double_path = -1 * (1 << 30);
    recur(A, double_path);

    return double_path;
}
