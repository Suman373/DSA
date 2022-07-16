// remove duplicates from the linkedlist and return the new head
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
        if(head == NULL) return NULL;
        struct ListNode *temp = head;
    if(head->val == val){
        head = head->next; // head points to the next node i.e.,node with same val removed
        return removeElements(head,val);
    }
    
    while(temp->next != NULL){
     // while next node is not null
        if(temp->next->val == val){
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }
    temp->next = NULL; //the last node 
    return head;
}