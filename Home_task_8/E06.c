/*

Среднее арифметическое массива
Считать массив из 12 элементов и подсчитать среднее арифметическое элементов массива. 

Данные на входе: 	12 целых чисел через пробел 
Данные на выходе: 	Среднее арифметическое в формате "%.2f" 

Пример №1
Данные на входе: 	4 -5 3 10 -4 -6 8 -10 1 0 5 7 
Данные на выходе: 	1.08 

Пример №2
Данные на входе: 	1 2 3 4 5 6 7 8 9 10 11 12 
Данные на выходе: 	6.50 

*/

#include <stdio.h>

#define  ARR_SIZE 12

int Input (int arr[], int n) //описание функции ввода
{
int i;
	for (i = 0; i < n; i++) //ввод массива
		scanf ("%d", &arr[i]);
	return i;
}

void PrintAveragev( int arr[], int n)
{
	int sum =0;
	for (int i = 0; i < n; i++)
	{	
		sum += arr[i];
	}
	float ave = (float)sum / n;
	printf("%.2f",ave);
}

int main()
{	
	int arr[ARR_SIZE];
	printf("Enter number: ");
	Input (arr, ARR_SIZE);
	PrintAveragev(arr, ARR_SIZE);
	return 0;
}

