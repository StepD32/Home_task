
#include <stdio.h>

int main(int argc, char **argv)
{
int a,b,c;	
	printf("Enter the dimensions of the sides of the triangle\n");
	scanf("%d %d %d",&a,&b,&c);
	if ((a+b > c) && (c+a > b) && (b+c > a)) printf("YES");
	else printf("NO");
	
	
	return 0;
}

