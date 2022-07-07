/* 
Given an integer arr nums, return true if any value appears at least twice in the arr, and return false 
if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void quicksort(int* arr, int l, int h){

	int i,j,pivot,temp;
	if(l<h){
		pivot=l;
		i=l;
		j=h;
	
	      while(i<j){
		      while(arr[i] <= arr[pivot] && i<h)
		       i++;
		      while( arr[j] > arr[pivot]) 
		    	j--;
		      if(i<j){
			   temp = arr[i];
			   arr[i]=arr[j];
			   arr[j]=temp;
		}
	}
	temp=arr[pivot];
	arr[pivot]=arr[j];
	arr[j]=temp;
	quicksort(arr,l,j-1);
	quicksort(arr,j+1,h);
  }
}//end of quicksort func
int main(){
	int n,*arr,i;
	// clrscr();
	printf("Enter the size:");
	scanf("%d",&n);
	arr = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,n-1);
	getch();
	return 1;
}