//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int len = 0;
    ListNode* p = new ListNode(0);
    p->next = A;
    A = p;
    ListNode* last = A;

    if(A->next == NULL) {
        return A->next;
    }

    while(last->next != NULL) {
        last = last->next;
        len += 1;
    }

    while(len > 0) {
        if(p->next->val < B) {
            p = p->next;
            len -= 1;
        }
        else {
            last->next = new ListNode(p->next->val);
            last = last->next;
            p->next = p->next->next;
            len -= 1;
        }
    }
    return A->next;
}
