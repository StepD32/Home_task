/*
E1 ДЗ 1
Среднее арифметическое чисел
Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива. 

Данные на входе: 	5 целых ненулевых чисел через пробел 
Данные на выходе: 	Одно число в формате "%.3f" 

Пример №1
Данные на входе: 	4 15 3 10 14 
Данные на выходе: 	9.200 

Пример №2
Данные на входе: 	1 2 3 4 5 
Данные на выходе: 	3.000 

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

void PrintAverage( int arr[], int n)
{
	float ave = 0;
	for (int i = 0; i < n; i++)
		ave+=arr[i];
	ave /= (float)n;
	printf("%.3f\n",ave);
}

int main()
{	
	int arr[ARR_SIZE];
	printf("Enter number: ");
	Input (arr, ARR_SIZE);
	PrintAverage(arr, ARR_SIZE);
	return 0;
}

