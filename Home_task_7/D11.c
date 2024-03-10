/*
Количество 1
Дано натуральное число N. Посчитать количество «1» в двоичной записи числа. 
Данные на входе: 	Натуральное число 
Данные на выходе: 	Целое число - количество единиц в двоичной записи числа. 

Пример №1
Данные на входе: 	5 
Данные на выходе: 	2 

Пример №2
Данные на входе: 	255 
Данные на выходе: 	8 

*/


#include <stdio.h>

unsigned int print_num(unsigned int a)
{
	unsigned int res = a%2;
	if (a > 1)
		res += print_num(a/2);
	return	res;
}


int main()
{
	unsigned int number;
	printf("Enter number: ");
	scanf("%d", &number);
	printf("%d\n",print_num(number));
	return 0;
}

