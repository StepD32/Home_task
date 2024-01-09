
#include <stdio.h>

int main(int argc, char **argv)
{
	int a,b; 
    scanf("%d" "%d", &a, &b);
    if (a <= b)
    { 
	
		for (int i = a; i <= b; i++)
		{ 		
			
			printf("%d ", i*i); 
		}
		return 0;
    } 
    
    printf("'a' more 'b', error!!");
    return 0;
	
}

