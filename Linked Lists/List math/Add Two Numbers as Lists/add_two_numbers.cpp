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
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode* ha = A;
    ListNode* hb = B;
    ListNode* res=new ListNode(0);
    ListNode* head = res;
    int carry = 0;

    while(A && B) {
        res->next = new ListNode((A->val+B->val+carry)%10);
        carry = (A->val+B->val+carry) / 10;
        A = A->next;
        B = B->next;
        res = res->next;
    }

    while (A){
        res->next = new ListNode((A->val+carry)%10);
        carry = (A->val+carry)/10;
        A=A->next;
        res=res->next;
    }

    while (B){
        res->next=new ListNode((B->val+carry)%10);
        carry = (B->val+carry)/10;
        B=B->next;
        res=res->next;
    }

    if (carry>0){
        res->next = new ListNode(carry);
    }

    return head->next;
}
