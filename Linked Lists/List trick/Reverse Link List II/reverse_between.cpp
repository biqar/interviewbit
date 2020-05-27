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
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode* head = new ListNode(-1);
    head->next = A;
    ListNode* prev = head;

    for(int i=0; i<m-1; i+=1) {
        prev = prev->next;
    }
    ListNode* reversedPrev = prev;

    prev = prev->next;      //reached m-th iteam
    ListNode* cur = prev->next;

    for(int i=m; i<n; i+=1){
        prev->next = cur->next;
        cur->next = reversedPrev->next;
        reversedPrev->next = cur;
        cur = prev->next;
    }
    return head->next;

    //TLE Code
    /*ListNode* head = A;

    for(int i=0; i<n-m; i+=1) {
        int p1 = m + i;
        int p2 = n - i;

        if(p1 >= p2) return A;

        ListNode* n1 = head;
        ListNode* n2 = head;
        while(p1-1 > 0) {
            n1 = n1->next;
            p1 -= 1;
        }

        while(p2-1 > 0) {
            n2 = n2->next;
            p2 -= 1;
        }

        int tmp = n1->val;
        n1->val = n2->val;
        n2->val = tmp;
    }
    return A;*/
}
