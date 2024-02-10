/*
E12
По убыванию и по возрастанию
Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию. 

Данные на входе: 	10 целых чисел через пробел 
Данные на выходе: 	Исходный массив. Первая часть отсортирована по возрастанию, вторая половина по убыванию. 

Пример №1
Данные на входе: 	14 25 13 30 76 58 32 11 41 97 
Данные на выходе: 	13 14 25 30 76 97 58 41 32 11 

Пример №2
Данные на входе: 	5 4 3 2 1 6 7 8 9 10 
Данные на выходе: 	1 2 3 4 5 10 9 8 7 6 


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

void PrintArray(int arr[], int n)
{
	for(int i = 0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
}

void swap(int arr[], int a, int b)
{
	arr[a] ^= arr[b];
	arr[b] ^= arr[a];
	arr[a] ^= arr[b];
}

void SortArray( int arr[], int n)
{
	int middle = n/2;
	for (int i = 0; i < n-1; i++)
	{	
		if (i < middle)
		{
			for (int j = (middle - 1); j > i; j--)
			{
				if (arr[j-1] > arr[j])
					swap(arr,j-1,j);
			}
		}
		else
		{
			for (int j = (n - 1); j > i; j--)
			{
				if (arr[j-1] < arr[j])
					swap(arr,j-1,j);
			}
		}
	}
}



int main()
{
	int arr[ARR_SIZE];
	printf("Enter number: ");
	Input (arr, ARR_SIZE);
	SortArray(arr, ARR_SIZE);
	PrintArray(arr, ARR_SIZE);
	return 0;
}

