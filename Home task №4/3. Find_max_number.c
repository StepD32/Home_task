#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{	
int32_t a,max_number;
	printf("Enter number: ");
	scanf("%" SCNd32, &a);	
	max_number = ((a/100)%10);
	if (((a/10)%10) > max_number) max_number = (a/10)%10;
	if ((a%10) > max_number) max_number = a%10;	
	printf("num = %d",max_number);	
	return 0;
}

