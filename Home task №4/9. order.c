#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
	
int32_t a,b,c;

	printf("Enter three numbers: ");
	scanf("%"SCNd32 "%"SCNd32 "%"SCNd32, &a, &b, &c);	
	a > b ? printf("No"): b < c ? printf("Yes"): printf("No");
	
	return 0;
}
