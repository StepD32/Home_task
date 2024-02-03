/*
E13 ДЗ 5
Вторая с конца ноль 
Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль. 

Данные на входе: 	10 целых чисел через пробел. 
Данные на выходе: 	Целые числа через пробел, у которых вторая с конца цифра - ноль 

Пример
Данные на входе: 	40 105 203 1 14 1000 22 33 44 55 
Данные на выходе: 	105 203 1 1000 

*/

#include <stdio.h>

#define  ARR_SIZE 10
#define  ZERO 0


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


int SelectArr(int _arr[], int _arr_new[], int n)
{
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if ((_arr[i] / 10) % 10 == ZERO)
		{
			_arr_new[count] = _arr[i];
			count++;
		}
	}
	return count;
}



int main()
{
	int arr[ARR_SIZE] = {0};
	int selArr[ARR_SIZE] = {0};

	printf("Enter number: ");
	Input (arr, ARR_SIZE);

	int in = SelectArr(arr, selArr, ARR_SIZE);
	PrintArray(selArr, in);

	return 0;
}

