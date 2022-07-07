// reverse using recursion
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int recursion(int num){
	int d=0,rev=0;
	if(num>0){
		d=num%10;
		rev = (rev*10)+d;
		printf("%d",rev);
		return recursion(num/10);
		
	}
	else
		return rev;
}

int main(){
	 int num;
	 // clrscr();
	 printf("Enter the no.:");
	 scanf("%d",&num);
	 // int k=recursion(num);
	 recursion(num);
	 // printf("Reverse is : %d",k);
	 getch();
	 return 1;
}