
#include <stdio.h>

int main(int argc, char **argv)
{
	int a,count;
	printf("Enter number: ");
    scanf("%d", &a);
    count = 0;
	for (int i = 0; a!=0; i++)
	{
		if (a%10 == 9)count++;	
		a = a/10;
	}	
	count == 1 ? printf("YES"):printf("NO");		
    return 0;	
}
