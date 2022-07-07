// inserting a node in the beginning of the linked list
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* head; // global stores the address of the head node

void insert(int c){
	struct Node* temp = (Node*)malloc(sizeof(Node));
	// (*temp).data=c; alternate
	temp->data = c;
	temp->next = head;
	head=temp;
}

void print(){
	struct Node* temp = head;
	printf("List is :\n");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;		
	}
	printf("\n");
}

int main(){
	int n,i,c;
	head = NULL;
	printf("Enter size of linkedlist:");
	scanf("%d",&n);
	printf("Enter the nos: ");
	for(i=0;i<n;i++){
		scanf("%d",&c); // we will accept the value inside c first, and then insert it to our linkedlist
		insert(c);
	}
	print();
	getch();
	return 1;
}