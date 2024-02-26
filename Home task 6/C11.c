/*
НОД
Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования.
int nod(int a, int b)
Данные на входе: 	Два целых положительных числа 
Данные на выходе: 	Одно целое число - наибольший общий делитель. 

Пример №1
Данные на входе: 	14 21 
Данные на выходе: 	7 
*/

#include <stdio.h>

unsigned int nod(unsigned int a, unsigned int b)
{
unsigned int div=2;
	while (1)
	{
	unsigned int tem_dev_a;
	unsigned int tem_dev_b;
		tem_dev_a = a%div;
		tem_dev_b = b%div;
		if (div > a && div > b)
		{
			return 0;
		}
		if( tem_dev_a == 0 && tem_dev_b == 0)
		{ 
			return div;
		}
		else
			div+=1;
	}
	return 0;
}

int main(void)
{
unsigned int a,b;
	printf("Enter two number:\n ");
	scanf("%d %d", &a, &b);
	unsigned int temp_not = nod(a, b);
	printf("The nod: %d\n",temp_not);
	return 0;
}

