//
// Created by Islam, Abdullah Al Raqibul on 5/23/20.
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
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector< vector<int> > ret;
    vector< vector<TreeNode*> > tv;
    vector<int> cv;
    vector<TreeNode*> ctv, tmp;

    cv.push_back(A->val);
    ctv.push_back(A);
    ret.push_back(cv);

    while(true) {
        if(ctv.size() == 0) break;
        cv.clear();
        tmp.clear();
        int sz = ctv.size();

        for(int i=0; i<sz; i+=1) {
            if(ctv[i]->left != NULL) {
                tmp.push_back(ctv[i]->left);
                cv.push_back(ctv[i]->left->val);
            }

            if(ctv[i]->right != NULL) {
                tmp.push_back(ctv[i]->right);
                cv.push_back(ctv[i]->right->val);
            }
        }

        if(tmp.size() == 0) break;

        ret.push_back(cv);
        cv.clear();
        ctv = tmp;
    }

    return ret;
}
