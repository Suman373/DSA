// implementing binary search
#include <stdio.h>
#include <conio.h>
void binary_search(int target,int arr[],int length){
	int l=0,u=length-1,m,flag=1;
	while(l<=u){
		m=(l+u)/2;
		if(target < arr[m]){
			u=m-1;
		}	
		else if(target > arr[m])
			l=m+1;
		else if(target == arr[m]){
			printf("Element is found at position %d\n",m+1);
			break;
		}
		else 
			flag=0;
	}
	if(!flag)
		printf("Element is not found!\n");
}

int main(){
	int i,target,length=0,arr[100];
	// clrscr();
	printf("Enter the no.of elements:");
	scanf("%d",&length);
	printf("Enter the array elements:");
	for(i=0;i<length;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the target:");
	scanf("%d",&target);
	binary_search(target,arr,length);
	getch();
	return 1;
}