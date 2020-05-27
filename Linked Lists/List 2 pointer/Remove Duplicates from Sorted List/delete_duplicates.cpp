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
ListNode* Solution::deleteDuplicates(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode* head = A;
    while(A != NULL) {
        if(A->next != NULL) {
            if(A->val == A->next->val) {
                A->next = A->next->next;
            }
            else {
                A = A->next;
            }
        }
        else break;
    }

    return head;
}
