// merge sort (D&Q approach)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

 void merge(int arr[],int l,int mid,int u){
	int i,j,k,brr[100];
	i = l;
	j = mid+1;
	k=l;
	while(i<=mid && j<=u){
		//placing elements in correct(ascending)order
		if(arr[i] <= arr[j]){
			brr[k]=arr[i];
			i++;
		}
		else{
			brr[k]=arr[j];
			j++;
		}
		k++;//increamenting the brr array pointer variable
	}
	//remaining elements (if exists in any of the subarrays)
	if(i>mid){
		while(j<=u){
			brr[k]=arr[j];
			j++;k++;
		}
	}
	else{
		while(i<=mid){
			brr[k]=arr[i];
			i++;k++;
		}
	}
	for(k=l;k<=u;k++){
		arr[k]=brr[k];
	}
}
void MergeSort(int arr[],int l,int u){
	if(l<u){
		int mid=(l+u)/2;
		MergeSort(arr,l,mid);
		MergeSort(arr,mid+1,u);
		merge(arr,l,mid,u); // function which will be merging the smaller sublists/subarrays
	}
}
int main(){
	int n,*arr,i;
	// clrscr();
	printf("Enter size:");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter the array: ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	MergeSort(arr,0,n-1);
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	getch();
	return 1;
}