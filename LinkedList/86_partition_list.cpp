//  partition the list such that values < x comes before the values >= x
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    if(head == NULL) return NULL;
    // creating the linkedlist for less than x
    struct ListNode* less_head = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    //     traversal pointer for the less_head 
    struct ListNode* less_ptr = less_head;
//     linkedlist for greater than x
    struct ListNode* greater_head = (struct ListNode*)malloc(sizeof(struct ListNode));
   
    // traversal pointer for the greater_head
    struct ListNode *greater_ptr = greater_head;
    
//     while we traverse the original list with head
    while(head != NULL){
        if(head->val < x){
            less_ptr->next = head;
            less_ptr = less_ptr->next; // till we get less than x
        }
        else{
            greater_ptr->next = head;
            greater_ptr = greater_ptr->next; // till greater than x
        }
        // head increases for next iteration
        head = head->next;
    }
    // to merge both lists, the last node must point null
    greater_ptr->next = NULL;
    // the last node of less_head must be pointed to first node of greater_head (note first node is empty, thus greater_head->next)
    less_ptr->next = greater_head->next;
    // return the new head
    return less_head->next; // node after the empty node less_head 
            
}