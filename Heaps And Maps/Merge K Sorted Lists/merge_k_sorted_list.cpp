//
// Created by Islam, Abdullah Al Raqibul on 11/26/19.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &lists) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode* head = new ListNode(0);

    if(lists.size()==0) {
        return NULL;
    }

    int sz = lists.size();
    head->next = lists[0];
    ListNode *p;
    ListNode *q;

    for(int i=1; i<sz; i+=1) {
        p = head;
        q = lists[i];
        while(q) {
            if(!p->next) {
                p->next = q;
                break;
            }

            if(p->next->val < q->val) {
                p = p->next;
            }
            else {
                ListNode *l = p->next;
                p->next = q;
                q = q->next;
                p->next->next = l;
                p = p->next;
            }
        }
    }
    return head->next;
}
