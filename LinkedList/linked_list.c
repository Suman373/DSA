// implementing linked list ds in c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node{
	//int and a pointer to the struct node
	int data;
	struct Node* link; // pointer to node
};
int main(){
	Node* A;
	A = NULL;
	Node* temp = (Node*)malloc(sizeof(Node));// allocate a memory for temp of size of Node
	temp -> data = 2;
	temp -> link = NULL; // only node in our LL
	A = temp; // A holds the address of our node
	printf("The node data is: %d at address : %D \n",temp->data,A);//prints the value of the node value

	// new node, we use temp1 and never modify A(stores the address of the head node)
	Node* temp1 = A;
	//traversal, and adding node in the end
	while(temp1->link != NULL){
		temp1 = temp1->link;
	}
	temp1 -> link=temp;
	temp1->data=5;
	printf("New node added in the end whose data is: %d at NULL\n",temp1->data);
	// exit(0);
	return 0;
}