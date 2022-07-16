// remove nth node from the end
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *traverse = head;
    int count=0;
    if(head==NULL) return head;
    // counting the length of the linkedlist first
    while(traverse != NULL){
        count++;
        traverse = traverse->next;
    }
    
    if(n<0 || n>count) return NULL;
    
    int pos = count-n +1 ; // since 2nd from ending is 3rd+1 from beginning
    traverse = head;
    
    if(n==count){
        head = traverse->next;
        free(traverse);
        return head;
    }
    
    for(int i=0;i<pos-2;i++){
        traverse = traverse->next;
    }
        struct ListNode* temp = traverse->next;
        traverse->next = temp->next;
        free(temp); 
        return head;
}