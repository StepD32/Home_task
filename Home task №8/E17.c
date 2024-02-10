/*
E17
Только один раз
Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран. 

Данные на входе: 	10 целых чисел через пробел 
Данные на выходе: 	Элементы которые встречаются только один раз через пробел 

Пример
Данные на входе: 	5 -4 0 1 4 -3 -3 3 0 2 
Данные на выходе: 	5 -4 1 4 3 2  
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
		printf("%d ",arr[i]);
	printf("\n");
}

int FreqOneSelectArr(int _arr[], int _arr_pos[], int n)
{
	int match = 0;
	int index_pos = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j=0; j < n; j++)
		{
			if((_arr[j] == _arr[i]))
				match++;
		}
		if(match == 1)
			_arr_pos[index_pos++] = _arr[i];
		match = 0;
	}
	return index_pos;
}

int main()
{
	int arr[ARR_SIZE] = {0};
	int arrfreg[ARR_SIZE] = {0};

	printf("Enter number: ");
	Input (arr, ARR_SIZE);

	int num = FreqOneSelectArr(arr, arrfreg, ARR_SIZE);
	PrintArray(arrfreg,num);
	return 0;
}

