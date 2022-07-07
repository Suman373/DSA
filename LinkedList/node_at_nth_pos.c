// inserting node at the nth position in a linkedlist
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data; // data
	struct Node* next; //link
};

//global head
struct Node* head;


void Print(){
	struct Node* temp = head;
	temp = head;
	// traversing the list
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}


void Insert(int data,int n){
	struct Node* temp1 = (Node*)malloc(sizeof(Node));
	temp1->data = data;
	temp1->next = NULL; // considering it to be the first 

	if(n==1){
		temp1->next=head;
		head=temp1;
		return; 
	}
	struct Node* temp2 = head;
	for(int i=0;i<n-2;i++){
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

int main(){
	head = NULL; // null head, empty list
	Insert(2,1); //2
	Insert(3,2); //2 3 
	Insert(4,1); //4 2 3
	Insert(5,2); //4 5 2 3
	// print func
	Print();
	return 0;
}
