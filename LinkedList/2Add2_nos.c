//  add two numbers, whose digits are presented via LinkedList
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void InsertNode(struct ListNode** head, struct ListNode** temp, struct ListNode** length , int sum){
    if(*head == NULL){
        //list empty
        *temp = *head = *length; 
        (*head)->val = sum; // add value
    }
    else{
        *temp = (*temp)->next = *length;
        (*temp)->val = sum;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry=0,sum=0; // initially 0
//     the head and temp pointers are for insertion of nodes in the new linkedlist 
    struct ListNode *head=NULL,*temp=NULL,*length;
    while(l1 != NULL & l2 != NULL){
         sum = l1->val + l2->val + carry ; // storing sum 
        carry = sum /10 ; // we store the carry to be added to next value
        sum %= 10; // after carry, sum is converted to the last digit of total sum
        InsertNode(&head, &temp, &l1, sum); // inserting node via func
        // iterate
        l1 = l1->next;
        l2 = l2->next;
        temp->next = NULL; // reset for the next iteration
    }
//     edge cases for list length not equal
    if(l1 != NULL){
        length = l1;
    }
    else
        length = l2; 
    //  iterate over the greater list to add the remaining no.s to the linkedlist
    while(length != NULL){
         sum = length->val + carry ; // remaining list val  + the carry
        carry = sum/10;
        sum %= 10;
        InsertNode(&head , &temp, &length, sum);    
        length = length->next;
        temp->next = NULL; //reset temp 
    }
    // carry remains 
    if(carry != 0){
        struct ListNode *carryPtr = (struct ListNode*)malloc(sizeof(struct ListNode)); // allocate mem for a new node 
        carryPtr->val = carry; 
        carryPtr->next = NULL;
        temp->next = carryPtr; // link new node to the last added node in thelist
    }
    
    return head; // head of the new linkedlist formed
}