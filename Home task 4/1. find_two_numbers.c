#include <stdio.h>

int main(void)
{
int a,b;
	printf("Enter two numbers\n");
	scanf("%d %d",&a, &b);
	if (a >= b) printf("Number: %d %d\n", b, a);
	else printf("Number: %d %d\n",a,b);
	return 0;
}

