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
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if (A == NULL) {
        return NULL;
    }

    ListNode *p = A;
    ListNode *q = A;
    while(true) {
        if(p->next != NULL) {
            p=p->next;
        }
        else {
            return NULL;
        }

        if(q->next != NULL && q->next->next != NULL) {
            q=q->next->next;
        }
        else {
            return NULL;
        }

        if(p==q) {
            q = A;
            while(p != q) {
                p = p->next;
                q = q->next;
            }
            return p;
        }
    }
}
