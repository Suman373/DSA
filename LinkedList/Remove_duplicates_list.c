/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *traverse = head;
    if(head == NULL) return head;
//      tempnode ptr
    while(traverse != NULL && traverse->next != NULL) {
        // if duplicate , delete the 2nd one
        if( traverse->val==traverse->next->val){
            traverse->next = traverse->next->next;
        }
        else
            traverse = traverse->next;
    }
    return head;
}