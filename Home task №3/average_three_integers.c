#include <stdio.h>

int main(int argc, char **argv)
{
int a,b,c;
float ave;
	printf("Enter three number:\n");
	scanf("%d%d%d",&a,&b,&c);
	ave = (a+b+c)/3.; //ave = (float)(a+b+c)/3; 	 	
 	printf("The average of three numbers = %.2f\n",ave); 
	return 0;

}

