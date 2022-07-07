// reverse_arr_recursion
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int rev(int arr[],int l,int u){
	// int temp=0;
	if(l>=u)
		return 1;
	// temp=arr[l];
	// arr[l]=arr[u];
	// arr[u]=temp;
	arr[l]=arr[l]+arr[u];
	arr[u]=arr[l]-arr[u];
	arr[l]=arr[l]-arr[u];
	return rev(arr,l+1,u-1);
}	
int main(){
	int n,i,*arr;
	// clrscr();
	printf("Enter the size of array:");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	rev(arr,0,n-1);
	printf("Reversed array is:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	getch();
	return 0;
}