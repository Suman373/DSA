#include <stdio.h>
#include <stdlib.h>
// creating the structure
struct Node{
	int data;
	struct Node* next;
};
// our global head , to be accessed from every function
struct Node* head;
// print the linkedlist
void Print(){
	struct Node* print_temp=head;
	while(print_temp != NULL){
		printf("%d ",print_temp->data);
		print_temp = print_temp->next;
	}
	printf("\n");
}
// insert nodes in the end of the list
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
void Delete(int n){
	struct Node* preNode = head;
	if(n==1){
		head = preNode->next; // head points to the node after 1st node
		free(preNode);
		return;
	}
	int i;
	for(i=0;i<n-2;i++){
		preNode = preNode->next;
		//preNode points to the n-1th node, which is the node before the target node
	}
	struct Node* tempNode = preNode->next; // new pointer tempNode points to the address of (nth)node
	preNode->next = tempNode->next; // now the (n-1)th node points to the element after nth node i.e., (n+1)th node
	free(tempNode); // deletes the memory for nth node 
	Print();
}

// main function
int main(){
	head = NULL;
	int size,n=0,pos=0;
	printf("Enter the size of the list:");
	scanf("%d",&size);
	for(int i=0;i<size;i++){
		printf("Enter the no.: ");
		scanf("%d",&n);
		Insert(n); // inserting element in the end of the list
	}
	// print the nodes/elements of the linked list 
	printf("The linked list elements are: ");
	Print(); // invokation
	comeBack:
	printf("Enter the pos to delete (1-%d)\n",size);
	scanf("%d",&pos);
	// position handling
	if(pos<=0 || pos>size){
		 printf("Wrong position entered!\n");
		 goto comeBack;
		 // exit(0);
	}
	// delete function to delete the node
	Delete(pos);
	return 1;
}

