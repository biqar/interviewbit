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
int Solution::kthsmallest(TreeNode* root, int k) {
    stack<TreeNode*> s;
    int res = 0;

    while(!(s.empty() && root==NULL)) {
        if(root != NULL) {
            s.push(root);
            root = root->left;
        } else {
            TreeNode* t = s.top();
            s.pop();
            k -= 1;
            if(!k) return t->val;
            root = t->right;
        }
    }
}
