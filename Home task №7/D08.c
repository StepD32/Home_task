/*
Составить рекурсивную функцию, Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае. 

Данные на входе: 	Два целых числа через пробел. 
Данные на выходе: 	Последовательность целых чисел. 

Пример №1
Данные на входе: 	5 2 
Данные на выходе: 	5 4 3 2 

Пример №2
Данные на входе: 	2 7 
Данные на выходе: 	2 3 4 5 6 7 

*/


#include <stdio.h>

void print_num(int a, int b)
{
	printf("%d ", a);
	if (a > b)
		print_num(a - 1, b);
	if (a < b)	
		print_num(a + 1, b);


}


int main()
{
	int first_number,second_number;
	printf("Enter two number: ");
	scanf("%d%d", &first_number,  &second_number);
	print_num(first_number, second_number);
	return 0;
}

