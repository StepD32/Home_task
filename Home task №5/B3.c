
#include <stdio.h>

int main(int argc, char **argv)
{
	int a,b,sum; 
	printf("Enter two number: ");
    scanf("%d" "%d", &a, &b);
    if (a <= b)
    { 	
		for (int i = a; i <= b; i++) sum +=i*i;
		printf("Sum %d\n", sum);
		return 0;
    }     
    printf("'a' more 'b', error!!");
    return 0;
	
}
