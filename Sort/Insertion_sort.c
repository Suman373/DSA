// COde for insertion sort, insertion sort is used to arrange an array by comparing an element from unsorted right portion with
// the element from sorted part on left side. This method is called as such because an element is inserted in its correct postition
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main(){
	int n,temp,j,*arr;
	// clrscr();
	printf("Enter size of array :");
	scanf("%d",&n); // size of array
	arr=(int*)malloc((n+1)*sizeof(int));
	//entering array elements
	printf("Enter the elements of the array:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	// INSERTION SORT STARTS HERE.....
	for(int i=1;i<n;i++){
		temp=arr[i];
		j=i-1;// j starts 1 index before the unsorted list
		while(j>=0 && arr[j]>temp)// while j loop is decreamenting and checking the greater than validity
		{
			arr[j+1]=arr[j];//right shift of greater element in sorted sublist
			j--;
		}
		arr[j+1]=temp;// when the temp value is greater than element in sorted part(sublist)
	}
	//end of for loop
	printf("Sorted array is:\n");
	for(int i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}

}