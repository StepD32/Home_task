/*
Посчитать числа
Дана последовательность ненулевых целых чисел, в конце последовательности число 0. 
Подсчитать количество чисел. 

Данные на входе:		Целые ненулевые числа. В конце последовательности ноль. Ноль в последовательность не входит. 
Данные на выходе:	Одно целое число - количество чисел в последовательности. 

Пример №1
Данные на входе:	15 22 2 4 1 6 0 
Данные на выходе:	6  
*/


#include <stdio.h>
 
int main(void)
{
unsigned int a,count=0;
	printf("Enter number:\n ");
	do
	{
		scanf("%d", &a); 
		count++;
	}while(a !=0);
	printf("the number of numbers in a sequence %d",count-1);
	return 0;
}