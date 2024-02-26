/*

E5
Сумма положительных элементов
Считать массив из 10 элементов и подсчитать сумму положительных элементов массива. 

Данные на входе: 	10 целых чисел через пробел 
Данные на выходе: 	Одно целое число - сумма положительных элементов массива 

Пример №1
Данные на входе: 	4 -5 3 10 -4 -6 8 -10 1 0 
Данные на выходе: 	26 

Пример №2
Данные на входе: 	1 -2 3 -4 5 -6 7 -8 9 0 
Данные на выходе: 	25 

*/

#include <stdio.h>

#define  ARR_SIZE 10

int Input (int arr[], int n) //описание функции ввода
{
int i;
	for (i = 0; i < n; i++) //ввод массива
		scanf ("%d", &arr[i]);
	return i;
}

void PrintSumPositiv( int arr[], int n)
{
	int SumPos = 0;
	for (int i = 0; i < n; i++)
	{	
		if(arr[i] > 0)
			SumPos += arr[i];
	}
	printf("%d\n",SumPos);
}

int main()
{	
	int arr[ARR_SIZE];
	printf("Enter number: ");
	Input (arr, ARR_SIZE);
	PrintSumPositiv(arr, ARR_SIZE);
	return 0;
}

