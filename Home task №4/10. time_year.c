#include <stdio.h>

int main(int argc, char **argv)
{
int a;	
	printf("Enter month number\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1 ... 2:
			printf("Winter\n");
			break;
		case 3 ... 5 :
			printf("Spring\n");
			break;
		case 6 ... 8:
			printf("Summer\n");
			break;
		case 9 ... 11:
			printf("Autumn \n");
			break;	
		case 12:
			printf("Winter\n");
			break;
		default:
			break;
	}
	
	return 0;
}

