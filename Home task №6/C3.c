/*
Среднее арифметическое чисел
Написать функцию, которая возвращает среднее арифметическое двух переданных ей аргументов (параметров).
int middle(int a, int b)
Данные на входе: 	Два целых неотрицательных числа 
Данные на выходе: 	Одно целое число 

Пример №1
Данные на входе: 	5 7 
Данные на выходе: 	6 

Пример №2
Данные на входе: 	10 20 
Данные на выходе: 	15 
*/
#include <stdio.h>


unsigned int middle(unsigned int a, unsigned int b)
{
unsigned int res;
	res = (a+b)/2;
	return res;
}

int main(void)
{
unsigned int first_number, second_number, average=0;
	printf("Enter two number:\n ");
	scanf("%d %d", &first_number,&second_number);
	average = middle(first_number,second_number);
	printf("Average number: %d\n",average);
	return 0;
}

