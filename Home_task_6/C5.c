/*
Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования. 

Пример №1
Данные на входе: 	Одно целое положительное число N 
Данные на выходе: 	Целое число - сумма чисел от 1 до N 

Пример №2
Данные на входе: 	100 
Данные на выходе: 	5050 
*/
#include <stdio.h>

unsigned int sum_number(unsigned  int n)
{
unsigned int res=0;
	for(int i=0; i<=n; ++i)
	res += i;
	return res;
	
}

int main(void)
{
unsigned int number;
	printf("Enter number:\n ");
	scanf("%d", &number);
	unsigned int sum = sum_number(number);
	printf("The sum of the numbers: %d\n",sum);
	return 0;
}

