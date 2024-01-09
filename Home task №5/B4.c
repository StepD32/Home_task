/*
Ровно три цифры
Ввести целое число и определить, верно ли, что в нём ровно 3 цифры. 

Данные на входе:		Целое положительное число 
Данные на выходе:	Одно слово: YES или NO 

Пример №1
Данные на входе:	123 
Данные на выходе:	YES 

Пример №2
Данные на входе:	1234 
Данные на выходе:	NO
*/

#include <stdio.h>

int main(int argc, char **argv)
{
	int a,count;
	printf("Enter number: ");
    scanf("%d", &a);
	for (count = 0; a!=0; count++)a = a/10;	
	count==3 ? printf("YES"):printf("NO");		
    return 0;
	
}
