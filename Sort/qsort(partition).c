// implementing quick sort using function partition
// doesnt work till now
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int partition(int arr[],int l,int h){
	int pivot=arr[l];
	int i=l,j=h,temp;
	while(i<j){
		//increament i till it gets element >= pivot
		do{
			i++;
		}while(arr[i]<=pivot);
		
		//decreament j till it gets element < pivot
		do{
			j--;
		}while(arr[j]>pivot);
		// while i<j , means we don't have pivot position yet
		if(i<j){
			// swap(arr[i],arr[j]);
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}//end of while looop

		//when i>j, we swap our arr[l] with el at j
		//swap(arr[l],arr[j]);
		temp=arr[l];
		arr[l]=arr[j];
		arr[j]=temp;
		return j;
}

void QuickSort(int arr[],int l,int h){
	if(l<h){
		int j=partition(arr,l,h);
		QuickSort(arr,l,j);
		QuickSort(arr,j+1,h);
	}
}

int main(){
	int n, *arr,i;
	printf("Enter size of the array:");
	scanf("%d",&n);
	arr=(int*)malloc((n)*sizeof(int));
	printf("Enter the array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	QuickSort(arr,0,n-1);
	printf("Sorted array is:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	getch();
	return 0;
}