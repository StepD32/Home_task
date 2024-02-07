#include <stdio.h>
 
void PrintDigist(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		if (arr[i] > 0)
			printf("%d %d\n", i, arr[i]);
}
 
void count_digits(char n[], int* res)
{
	for (int i=0; n[i]!=0; i++)
		res[n[i] - '0']++;
}
 
int main()
{
	enum {BUFFER_SIZE = 1000};
	char buffer[BUFFER_SIZE];
	int arr_dig[10] = {0};
	int count = scanf("%[^'\n']", buffer);
	printf("%s\n",buffer);
	printf("%d",count);
	//scanf("%[0-9]", buffer);
	count_digits(buffer, arr_dig);
	//PrintDigist(r,10);
	return 0;
}
