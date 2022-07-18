// partition the list such that the odd nodes come before the even nodes. 1st node is odd, 2nd node is even
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(head==NULL) return NULL;
//      we are storing 2 lists for odd and even and then merging it
    struct ListNode *oddPtr = head; // traversing odd nodes and storing
    struct ListNode *evenPtr = head->next; // traversing even nodes and storing
    struct ListNode *evenHead  = evenPtr; // for merging odd list to even list
    
    while(evenPtr !=NULL && evenPtr->next != NULL){
        oddPtr->next = evenPtr->next; // 1st node points to 3rd node
        oddPtr = oddPtr->next; // oddPtr will move one node
        evenPtr->next = oddPtr->next; // 2nd node points 4th node
        evenPtr = evenPtr->next; // evenPtr will move one node
    }
    // we exit when the even ptr or next odd is null
    oddPtr->next = evenHead; // last node of odd list points to the 1stNode of even list
    return head; // head of the reordered/merged list
        
}