// quick sort algorithm to sort an array using left,right pointers and a pivot point.
#include <stdio.h>
#include <conio.h>

void quicksort(int array[], int first, int last){
	int i,j,pivot,temp;
	if(first<last){
		pivot=first;
		i=first;
		j=last;
	      while(i<j){
		      while(array[i] <= array[pivot] && i<last)
		       i++;
		      while( array[j] > array[pivot]) 
		    	j--;
		      if(i<j){
			   temp = array[i];
			   array[i]=array[j];
			   array[j]=temp;
		}
	}
	temp=array[pivot];
	array[pivot]=array[j];
	array[j]=temp;
	quicksort(array,first,j-1);
	quicksort(array,j+1,last);
  }
}

int main(){
	int i,n,array[100];
	printf("Enter no. of elements:");
	scanf("%d",&n);
	printf("Enter the array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	quicksort(array,0,n-1);// sending the array with first index and last index of the array 
	printf("The sorted array in ascending order:");
	for(i=0;i<n;i++){
		printf("%d ",array[i]);
	}
	getch();
	return 0;
}