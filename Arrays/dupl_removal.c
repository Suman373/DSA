// duplicate removal from an array, max 2 duplicates exist
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void display(int arr[],int n){
	printf("Array without duplicates...\n");
	for(int i=0;i<n;i++){
		if(arr[i]==-999) continue;
		else printf("%d ",arr[i]);
	}
}
void bub_sort(int arr[],int n){
	int i,j,temp;
	for(i=0;i<n;i++){
		//ascending order bsort
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void remove_duplicate(int arr[],int n){
	int flag=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]==arr[j]){
				flag=1;
				arr[i]=-999;
				arr[j]=-999;
			}
		}
	}
	if(flag){
		display(arr,n);
	}
	else{
		printf("Duplicates doesn't exist!\n");
		exit(0);
	}

	
}

int main(){
	int *arr,i,n;
	// clrscr();
	printf("Enter the size of the array:");
	scanf("%d",&n);
	// array initialisation
	arr = (int*)malloc((n+1)*sizeof(int));
	// input
	printf("Enter the array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	//invoking bub sort function
	bub_sort(arr,n);
	//remove duplicates
	remove_duplicate(arr,n);
	getch();
	return 1;

}