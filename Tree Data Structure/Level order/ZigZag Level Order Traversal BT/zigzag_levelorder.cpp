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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<TreeNode*> > tr;
    vector<TreeNode*> t, c;
    vector<vector<int> > ret;
    vector<int> v;
    int turn = 0;

    v.push_back(A->val);
    ret.push_back(v);
    t.push_back(A);
    tr.push_back(t);

    while(true) {
        t = tr[turn];
        v.clear();
        c.clear();
        int sz = t.size();

        if(sz == 0) break;

        for(int i=0; i<sz; i+=1) {
            if(t[i]->left != NULL) {
                c.push_back(t[i]->left);
            }

            if(t[i]->right != NULL) {
                c.push_back(t[i]->right);
            }
        }

        sz = c.size();

        if(sz == 0) break;

        if(turn%2 == 0) {
            for(int i=sz-1; i>=0; i-=1) {
                v.push_back(c[i]->val);
            }
        } else {
            for(int i=0; i<sz; i+=1) {
                v.push_back(c[i]->val);
            }
        }
        ret.push_back(v);
        tr.push_back(c);
        turn += 1;
    }
    return ret;
}
