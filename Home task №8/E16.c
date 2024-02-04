/*
Чаще других
Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1. 

Данные на входе: 	10 целых числе через пробел 
Данные на выходе: 	Одно число, которое встречается чаще других. 

Пример
Данные на входе: 	4 1 2 1 11 2 34 11 0 11  
Данные на выходе: 	11 
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
	printf("\n");
}

void SortArray( int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = (n - 1); j > i; j--)
		{
			if (arr[j-1] > arr[j])
			{
				arr[j-1] ^= arr[j];
				arr[j] ^= arr[j-1];
				arr[j-1] ^= arr[j];
			}
		}
	}
}

int FreqSelectArr(int _arr[], int n)
{
	int newfreg = 0;
	int lastfreg = 0;

	int count = 1;
	int lastcount = 0;

	for(int i = 0; i < n; i++)
	{
		if (_arr[i] == _arr[i+1])
		{
			count++;
			newfreg = _arr[i];
		}
		else
		{
			if(count > lastcount){
				lastcount = count;
				lastfreg = newfreg; 
				count = 1;
			}
		}
		
	
	}
	return lastfreg;
}

int main()
{
	int arr[ARR_SIZE] = {0};

	printf("Enter number: ");
	Input (arr, ARR_SIZE);

	SortArray(arr, ARR_SIZE);
	int num = FreqSelectArr(arr, ARR_SIZE);
	printf("num freq %d\n", num);

	return 0;
}

