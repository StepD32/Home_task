#include <stdio.h>
 
int main(void)
{
unsigned int a,min,max;
    printf("Enter number: ");
    scanf("%d", &a);
    max = 0;
    min = a;    
    int num;
    while (a != 0)
    { 
		num = a%10;
		if (max<num) max=num;
		if (min>num) min=num;
		a /=10;
						
    }
    printf("min = %d, max = %d\n  ",min,max);  
    return 0;
}
