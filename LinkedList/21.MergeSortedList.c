/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    
    // comparison 
    struct ListNode* tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* currentNode = tempNode; // currentNode points to the Null, empty list
    int data1,data2;
    while(list1 != NULL && list2 != NULL){
        
        if(list1->val < list2->val){ // ascending order 
            currentNode->next = list1;
            list1 = list1->next;
        }
        else{
            currentNode->next = list2;
            list2 = list2->next;
        }
        
        currentNode = currentNode->next;
        
    }
    //edge cases where the list1 has not ended yet
    if(list1 != NULL){
        currentNode->next = list1; // prev Node points to the next Node
        list1 = list1->next;
    }
    if(list2 != NULL){
        currentNode->next = list2; // for list 2 same as above
        list2 = list2->next;
    }
    return tempNode->next;
}