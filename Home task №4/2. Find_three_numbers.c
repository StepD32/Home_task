#include <stdio.h>

int main(void)
{
int a,b,c;
	printf("Enter theer numbers\n");
	scanf("%d %d %d",&a, &b, &c);
	if (a > b)
	{
		if(a > c) printf("Number: %d\n", a);
		else printf("Number: %d\n", c);
	}		
	else 
	{	if (b > c) printf("Number: %d\n",b);
		else printf("Number: %d\n",c);
	}
	return 0;
}

