/*
Возвести в степень
Написать рекурсивную функцию возведения целого числа n в степень p.
int recurs_power(int n, int p)
Используя данную функцию, решить задачу.

Данные на входе: 	Два целых числа -100 >= n >= 100 и 0 >= p >= 100
Данные на выходе: 	Одно целое число n в степени p

Пример №1
Данные на входе: 	2 3
Данные на выходе: 	8

Пример №2
Данные на входе: 	3 4
Данные на выходе: 	81
*/


#include <stdio.h>

int recurs_power(int n, int p)
{
	//printf("n:%d \n", n);
	if (p != 0)
	{
		p--;
		return n * recurs_power(n,p);
	}
	return 1;
}


int main()
{
	int a,b;
	printf("Enter two number: ");
	scanf("%d %d", &a, &b);
	int temp_not = recurs_power(a, b);
	printf("The power: %d\n",temp_not);
	return 0;
}

