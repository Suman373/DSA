// check palindrome string using recursion
#include <stdio.h>
#include <conio.h>
#include <string.h>

int palindrome(char str[],int l,int h){
	if(l>=h) return 1;

	if(str[l]!=str[h])
		return 0;

	return palindrome(str,l+1,h-1);
}
int main(){
	char str[20],k,len=0;
	// clrscr();
	printf("Enter the word :");
	scanf("%[^\n]s",str);
	len=strlen(str);
	k=palindrome(str,0,len-1);
	if(k)
		printf("String is palindrome!\n");
	else
		printf("String is not palindrome!\n");
	getch();
	return 0;
}