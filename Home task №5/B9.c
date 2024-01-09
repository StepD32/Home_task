
#include <stdio.h>

int main(int argc, char **argv)
{
	int a,num;
	printf("Enter number: ");
    scanf("%d", &a);    
	while(a>0)
	{	
		num = a%10;
		if(num%2!=0)
		{
			printf("NO");
			return 0;
		}
		a=a/10;
	}
	printf("YES");
    return 0;	
}
