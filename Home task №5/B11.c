#include <stdio.h>
 
int main(void)
{
unsigned int a,b,not_a;
    printf("Enter number: ");
    scanf("%d", &a);
    while (a != 0)
    { 
		b = a%10;
		a /=10;
		not_a = not_a*10+b;
				
    }
    printf("not_a = %d",not_a);
    return 0;
}
