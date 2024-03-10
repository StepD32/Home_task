#include <stdio.h>

int main(int argc, char **argv)
{
int a,mul;
	printf("Enter a three-digit number:\n");
	scanf("%d",&a);
	mul = a%10;
	mul *=((a/10)%10);
	mul *=((a/100)%10);
	printf("A work of a three-digit number = %d\n",mul); 
	return 0;

}

