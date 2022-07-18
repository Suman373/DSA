// find the intersecting node of 2 singly linkedlists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
//      pointers for traversal
    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;
    while(ptrA != ptrB){
        // if ptrA reaches end, we reset it to head of 2nd list
        if(ptrA == NULL)
            ptrA = headB;
        else
            ptrA = ptrA->next;
        // ptrB reaches end, reset it to head of 1st list
        if(ptrB == NULL)
            ptrB = headA;
        else
            ptrB = ptrB->next;
    }
    return ptrA;
}