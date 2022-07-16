//  Sort a list using bubble sort
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

void Bsort(struct Node* head){
	// exchanging the data according to our comparison
	struct Node *end,*i,*j; // pointers
	int temp; // for swaps

	for(end = NULL ; end != head->next; end=i){
		for(i=head; i->next != end ; i=i->next){
			j = i->next; // adjacent node
			if(i->data >  j->data){
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			} // since we are arranging in ascending order
		}
	}
}
void Print(){
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
	printf("Sorting....ready to print\n");
	Bsort(head);
	Print();
	getch();
	return 1;
}
