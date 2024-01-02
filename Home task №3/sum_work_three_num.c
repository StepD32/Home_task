#include <stdio.h>

int main(int argc, char **argv)
{
int a,b,c,sum,mul;
	printf("Enter three number:\n");
	scanf("%d%d%d",&a,&b,&c);
	sum = a+b+c; 	
 	printf("The sum of three numbers = %d\n",sum);
 	mul = a*b*c;
 	printf("The mul of three numbers = %d\n",mul); 
	return 0;

}

