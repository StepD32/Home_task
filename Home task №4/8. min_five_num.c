#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
int32_t a,b,c,d,e;
int32_t min_number = 0;	

	printf("Enter five numbers: ");
	scanf("%"SCNd32 "%"SCNd32 "%"SCNd32 "%"SCNd32 "%"SCNd32, &a, &b, &c, &d, &e);	
	min_number =  a > b ?  b : a;
    min_number = min_number > b ? b: min_number;
    min_number = min_number > c ? c: min_number;
    min_number = min_number > d ? d: min_number;
	min_number = min_number > e ? e: min_number;
    printf("Min numbers: %" PRId32 "\n" , min_number);
	return 0;
}
