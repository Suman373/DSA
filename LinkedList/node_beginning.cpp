// inserting a node in the beginning of the linked list

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

 Node* head; // global stores the address of the head node

void insert(int c){
	 Node* temp = new Node();
	// (*temp).data=c; alternate
	temp->data = c;
	temp->next = head;
	head=temp;
}

void print(){
	 Node* temp = head;
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
	cout << "ENter size of the linekdlist";
	scanf("%d",&n);
	printf("Enter the nos: ");
	for(i=0;i<n;i++){
		scanf("%d",&c); // we will accept the value inside c first, and then insert it to our linkedlist
		insert(c);
	}
	print();
	return 1;
}