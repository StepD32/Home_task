/*
Ровно одна цифра 9
Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9». 
Данные на входе:		Одно целое число 
Данные на выходе:	Одно слово: YES или NO  

Пример №1
Данные на входе:	193 
Данные на выходе:	YES 

Пример №2
Данные на входе:	1994 
Данные на выходе:	NO 

*/
#include <stdio.h>

int main(int argc, char **argv)
{
	int a,count;
	printf("Enter number: ");
	scanf("%d",&a);
	count = 0;
	for (int i=0; a!=0; i++)
	{
		int temp=a%10;
		if (temp==9)count++;
		a /=10;
	}	
	count==1 ? printf("YES"):printf("NO");
	return 0;
}
