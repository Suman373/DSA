// printing a linked list using RECURSION
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	int data; // value
	struct Node* next;// link
};

struct Node* Insert(struct Node* head,int data)
{
	struct Node* temp1 = (Node*)malloc(sizeof(Node)); // dyn allocation
	temp1->data=data;
	temp1->next=NULL;
	//for first element
	if(head==NULL){
		head=temp1;
	}
	else{
		struct Node* traverse=head;
			// we traverse until null
			while(traverse->next != NULL){
					traverse=traverse->next; // go to link of the next node until we reach the last node
			}
			traverse->next=temp1;}

	return head;// since head is locally declared, insert will return the modified head 
}

// print in normal order
void recursive_print(struct Node* head){
	if(head == NULL) return ; // when we reach the end of the list we exit the function

	printf("%d ",head->data); // print the value for each recursive call
	recursive_print(head->next); // recursive call
}

// print in reverse order
void recursive_reverse_print(struct Node* head){
	if(head == NULL) return ; // when we reach the end of the list we exit the function

	recursive_reverse_print(head->next); // recursive call before
	printf("%d ",head->data); // after the last node is reached, and then prints back the values
	
}
int main(){
	struct Node* head; //local head declartion
	head=NULL; // initially empty list
	int size,data;
	printf("Enter size of the list:");
	scanf("%d",&size);
	if(!size){ printf("Exiting/..."); exit(0);}
	for(int i=0;i<size;i++){
		printf("Enter data:\n");
		scanf("%d",&data);
		head=Insert(head,data); // we insert node and fetch the modified head , it helps when the user inserts node at any pos 
	}
	int choice;
	printf("Enter 1 for normal print,enter 2 for reverse print : ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			  printf("Printing the list :\n");
			  recursive_print(head);
			  break;
		case 2:
			  printf("Printing in reverse order : \n");
			  recursive_reverse_print(head);
			  break;
		default:
			printf("Invalid choice!\n");
			break;
	}
	getchar();
	return 1;
}