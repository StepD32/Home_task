/*
E19 ДЗ *
Цифры по порядку
Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N. 

Данные на входе: 	Одно натуральное число N 
Данные на выходе: 	Цифры через пробел 

Пример
Данные на входе: 	54412 
Данные на выходе: 	5 4 4 1 2 
*/

#include <stdio.h>

#define  ARR_SIZE 10



int EnterArr (int arr[], int _num) //описание функции ввода
{
	int i;
	for (i = 0; n > 0; i++) //ввод массива
	{
		arr[count] = _num%10;
		_num /=10;
	}
	return i;
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


void PrintArray(int arr[], int n)
{
	for(int i = 0; i<n; i++)
		printf("%d ",arr[i]);
	printf("\n");
}


int main()
{
	int num = 0;
	int arrNum [ARR_SIZE] = {0};

	scanf ("%d", &num);

	int count = EnterArr(arrNum,num);
	SortArray(arrNum,count);
	PrintArray(arrNum,count);

	return 0;
}

