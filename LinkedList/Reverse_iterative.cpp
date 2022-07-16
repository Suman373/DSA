#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* head;

void Insert(int data)
{
	struct Node* temp1 = (Node*)malloc(sizeof(Node));
	temp1->data=data;
	temp1->next=NULL;
	//for first element
	if(head==NULL){
		head=temp1;
		temp1->next=NULL;
		return;
	}
	struct Node* traverse=head;
	// we traverse until null
	while(traverse->next != NULL){
		traverse=traverse->next; // go to link of the next node until we reach the last node
	}
	traverse->next=temp1;
	// temp1->next=NULL;
}
//  reversing using iterative method
struct Node* Reverse(struct Node* head){
	if(head==NULL){
		printf("List is empty!");
		exit(0);
	}
	struct Node *currentPtr, *prevPtr, *nextPtr;
	currentPtr=head; // initially the currentPtr points to the 1st node
	prevPtr=NULL; // to fix the previous node

	while(currentPtr!=NULL){
		nextPtr = currentPtr->next; // points to the next node, node after our current 
		currentPtr->next = prevPtr; // current node now points to the prev node
		//  ---- reseting our pointers ----
		prevPtr = currentPtr; // the current node address is stored in the prev ptr now
		currentPtr = nextPtr; // the next node becomes the current now, moved one step forward
	}
	head = prevPtr;
	return head;

}
void Print(struct Node* head){
	struct Node* print_temp=head;
	while(print_temp != NULL){
		printf("%d ",print_temp->data);
		print_temp = print_temp->next;
	}
	printf("\n");
}
int main(){
	head=NULL; // initially empty list
	int size,data;
	printf("Enter size of the list:");
	scanf("%d",&size);
	for(int i=0;i<size;i++){
		printf("Enter data:\n");
		scanf("%d",&data);
		Insert(data);
	}
	Print(head); // print the normal list
	head=Reverse(head); // the new head aftering reversing is returned
	Print(head); // print the reversed list
	getchar();
	return 1;
}


