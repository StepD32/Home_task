#include <stdio.h>

int main(int argc, char **argv)
{
	int a,b;	
	printf("Enter a and b numbers\n");
	scanf("%d %d",&a, &b);
	(a == b) ? printf("Equal") : (a > b) ? printf("Above") : printf("Less") ;	
	return 0;
}

 
