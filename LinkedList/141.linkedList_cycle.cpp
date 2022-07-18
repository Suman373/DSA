/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL) return false;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    while(fast->next!=NULL){
        if(fast->next->next == NULL) break;
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast->next == slow) {
            return true;
        }
    }
    return false;
    
}