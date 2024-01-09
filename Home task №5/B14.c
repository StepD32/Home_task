#include <stdio.h>
 
int main(void)
{
unsigned int a,even=0,not_even=0;
    printf("Enter number: ");
    scanf("%d", &a); 
    int num;
    while (a != 0)
    { 
		num = a%10;
		if (num%2 == 0) even++;
		if (num%2 != 0) not_even++;
		a /=10;
						
    }
    printf("even = %d, not_even = %d\n  ",even,not_even);  
    return 0;
}
