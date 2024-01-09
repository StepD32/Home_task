
#include <stdio.h>

int main(int argc, char **argv)
{
	int a,count;
	printf("Enter number: ");
    scanf("%d", &a);
	for (count = 0; a!=0; count++)a = a/10;	
	count==3 ? printf("YES"):printf("NO");		
    return 0;
	
}
