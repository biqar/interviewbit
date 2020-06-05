//
// Created by Islam, Abdullah Al Raqibul on 6/4/20.
//

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(A == NULL) return NULL;

    RandomListNode* curr =  A;

    // creating copy of the nodes and setting next pointer
    // input: [given_0]->[given_1]-><<NULL>>
    // constructed: [given_0]->[new_0]->[given_1]->[new_1]-><<NULL>>
    while(curr != NULL) {
        RandomListNode* tmp = new RandomListNode(curr->label);
        tmp->next = curr->next;

        curr->next = tmp;
        curr = curr->next->next;
    }

    curr = A;
    // copying the random pointers
    while(curr != NULL) {
        if(curr->random != NULL) curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    curr =  A;
    RandomListNode* ret = curr->next;
    RandomListNode* ret_curr = ret;
    // decoupling deep-copy chain
    while(ret_curr->next != NULL) {
        curr->next = curr->next->next;
        ret_curr->next = ret_curr->next->next;

        curr = curr->next;
        ret_curr = ret_curr->next;
    }

    return ret;
}
