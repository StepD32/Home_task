/*

Отсортировать по последней цифре
Считать массив из 10 элементов и отсортировать его по последней цифре. 

Данные на входе: 	10 целых чисел через пробел 
Этот же массив отсортированный по последней цифре 

Пример №1
Данные на входе: 	14 25 13 30 76 58 32 11 41 97 
Данные на выходе: 	30 11 41 32 13 14 25 76 97 58 

Пример №2
Данные на входе: 	109 118 100 51 62 73 1007 16 4 555 
Данные на выходе: 	100 51 62 73 4 555 16 1007 118 109 


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


void SortArray( int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = (n - 1); j > i; j--)
		{
			if (arr[j-1]%10 > arr[j]%10)
			{
				arr[j-1] ^= arr[j];
				arr[j] ^= arr[j-1];
				arr[j-1] ^= arr[j];
			}
		}
	}
}


int main()
<<<<<<< HEAD
{	
	int arr[ARR_SIZE] = {0};
=======
{
	int arr[ARR_SIZE];
>>>>>>> f259411714dff6c9d7fa4c256edefdaec3ac9e00
	printf("Enter number: ");
	Input (arr, ARR_SIZE);
	SortArray(arr, ARR_SIZE);
	PrintArray(arr, ARR_SIZE);
	return 0;
}

