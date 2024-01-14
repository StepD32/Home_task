/*
Факториал
Составить функцию вычисления N!. Использовать ее при вычислении факториала
int factorial(int n)

Данные на входе: 	Целое положительное число не больше 20 
Данные на выходе: 	Целое положительное число 

Пример №1
Данные на входе: 	5 
Данные на выходе: 	120 
*/

#include <stdio.h>

unsigned long long factorial(unsigned int n)
{
unsigned long long res=1;
	for(int i=2; i<=n; i++)
	res *= i;
	return res;
}

int main(void)
{
unsigned long long number;
	printf("Enter number:\n ");
	scanf("%lld", &number);
	unsigned long long fac = factorial(number);
	printf("The factorial: %lld\n",fac);
	return 0;
}

