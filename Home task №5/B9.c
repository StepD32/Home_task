/*
Все цифры четные
Ввести целое число и определить, верно ли, что все его цифры четные. 
Данные на входе:		Одно целое число 
Данные на выходе:	YES или NO 

Пример №1
Данные на входе:	2684 
Данные на выходе:	YES 

Пример №2
Данные на входе:	2994 
Данные на выходе:	NO 
*/

#include <stdio.h>

int main(int argc, char **argv)
{
	int a,num;
	printf("Enter number: ");
    scanf("%d", &a);    
	while(a>0)
	{	
		num = a%10;
		if(num%2!=0)
		{
			printf("NO");
			return 0;
		}
		a=a/10;
	}
	printf("YES");
    return 0;	
}
