//  to check if the list is palindrome or not --> 2 pointers fast slow  and 3 pointers for reversing iteratively
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse_list(struct ListNode* slow){
    // to reverse the list 
    struct ListNode *prevPtr, *currentPtr, *nextPtr;
    currentPtr = slow; // starting pointer
    prevPtr = NULL;
    nextPtr = currentPtr->next;
    while(currentPtr != NULL){
        nextPtr = currentPtr->next;
        currentPtr->next = prevPtr; 
        prevPtr = currentPtr;
        currentPtr = nextPtr;
    }
    slow = prevPtr; // since currentPtr has reached NULL
    return slow;
}


bool isPalindrome(struct ListNode* head){
    if(head == NULL) return false;
//    initially both are starting from the 1st node
    struct ListNode *slow =head;
    struct ListNode *fast = head; 
    
    while(fast != NULL && fast->next!= NULL){
        fast = fast->next->next; // 2 steps
        slow = slow->next; // 1 step
    }
    // when our fast reaches null
    slow = reverse_list(slow); 
    fast = head; // reset the fast pointer
    
    while(slow != NULL){
        if(slow->val != fast->val)  return false; // not palindrome 
        // note that, list after the middle is reversed , now both slow //and fast pointers move  1 step
        slow = slow->next; // move 1step
        fast = fast->next; // move 1step 
    }
    return true;
}