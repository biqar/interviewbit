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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* head;

int getListLength() {
    int len = 0;
    ListNode* curr = head;

    while(curr != NULL) {
        len += 1;
        curr = curr->next;
    }
    return len;
}

TreeNode* func(int st, int nd) {
    if(st > nd) return NULL;

    int mid = st + (nd - st) / 2;

    TreeNode* left = func(st, mid-1);

    TreeNode* ret = new TreeNode(head->val);
    head = head->next;

    TreeNode* right = func(mid+1, nd);

    ret->left = left;
    ret->right = right;

    return ret;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    head = A;
    int len = getListLength();

    if(len == 0) return NULL;

    return func(0, len-1);
}
