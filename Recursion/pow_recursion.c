// power of a no. raised to n using recursion
#include <stdio.h>
#include <conio.h>

int recursion(int num,int n){
	if(n<1)
		return 1;
	else{
		return num*recursion(num,n-1);
	}	
}

int main(){
	int num,n;
	// clrscr();
	printf("Enter the no. and power:");
	scanf("%d%d",&num,&n);
	int k = recursion(num,n);
	printf("Result is:%d\n",k);
	getch();
	return 1;
}