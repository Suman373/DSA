/*
Algo:
  i)For this we are gonna make the array a Hashmap, from 0 to n-1. When we encounter element 'a', then increase the value of
   a%n th element by n. Then the freq of that element can be retrieved by dividing a%n th element by n


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int get_elements(int n){
	int *arr,*count;
	// dynamically allocating the memory for both our int array and the count array
	arr=(int*)malloc((n+1)*sizeof(int));
	count=(int*)malloc((n+1)*sizeof(int));
	printf("Enter the array elements:");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Searching for duplicate...\n");
	//+1 for ith position in
	for(int i=0;i<n;i++)
	{
		count[i]++;
		if(count[i]>1){
			return arr[i];
            break;
		}
		else continue;
	}
}

int main(){
	int nn;
	puts("Enter the size of array:");
	scanf("%d",&nn);
	int rv=get_elements(nn);
	puts("Duplicate is:");
	printf("%d",rv);
	return 0;
}