
#include <stdio.h>

int main(int argc, char **argv)
{
int a,b,c;	
	printf("Enter the dimensions of the sides of the triangle\n");
	scanf("%d %d %d",&a,&b,&c);
	if (a+b > c)
	{
		if (b+c > a)
		{
		    if (c+a > b) printf("YES");
		    else printf("NO");
		}
		else printf("NO");					
	}
	else printf("NO");
	
	
	return 0;
}

