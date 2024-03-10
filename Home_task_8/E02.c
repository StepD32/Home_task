/*
E2
Найти минимум
Ввести c клавиатуры массив из 5 элементов, найти минимальный из них. 

Данные на входе: 	5 целых чисел через пробел 
Данные на выходе: 	Одно единственное целое число 

Пример №1
Данные на входе: 	4 15 3 10 14 
Данные на выходе: 	3 

Пример №2
Данные на входе: 	1 2 3 4 -5 
Данные на выходе: 	-5 

*/
#include <stdio.h>

#define  ARR_SIZE 5

int Input (int arr[], int n) //описание функции ввода
{
int i;
	for (i = 0; i < n; i++) //ввод массива
		scanf ("%d", &arr[i]);
	return i;
}

void PrintMin( int arr[], int n)
{
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{	
		if(min > arr[i])
			min = arr[i];
	}
	printf("%d\n",min);
}

int main()
{	
	int arr[ARR_SIZE];
	printf("Enter number: ");
	Input (arr, ARR_SIZE);
	PrintMin(arr, ARR_SIZE);
	return 0;
}

