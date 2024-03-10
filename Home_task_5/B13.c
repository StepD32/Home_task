/*
Количество четных и нечетных цифр
Подсчитать количество четных и нечетных цифр числа. 

Данные на входе:	Одно целое неотрицательное число. 
Данные на выходе:	Два числа через пробел. Количество четных и нечетных цифр в числе. 

Пример №1
Данные на входе:	1234 
Данные на выходе:	2 2 

Пример №2
Данные на входе:	787 
Данные на выходе:	1 2 

*/

#include <stdio.h>

int main(void)
{
unsigned int a,even=0,not_even=0;
	printf("Enter number: ");
	scanf("%d", &a); 
	int num;
	while (a!=0)
	{
		num=a%10;
		if (num%2 == 0) even++;
		if (num%2 != 0) not_even++;
		a /=10;
	}
	printf("even = %d, not_even = %d\n  ",even,not_even);  
	return 0;
}