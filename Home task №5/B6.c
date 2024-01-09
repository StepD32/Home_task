#include <stdio.h>

int main(int argc, char **argv)
{
	int a,other_nums,num;
	printf("Enter number: ");
    scanf("%d", &a);
	if (a < 10){
		printf("NO ");
		return 0;
	}
	other_nums = a;
	for (int i = 0; a!=0; i++){
		num = a%10;
		if (num == other_nums){
			 printf("YES");
			 return 0;	
		}
		other_nums = num;
		a = a/10;	
	}	
	printf("NO");
}
