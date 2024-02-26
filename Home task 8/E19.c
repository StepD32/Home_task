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
	for (i = 0; _num > 0; i++) //ввод массива
	{
		arr[i] = _num%10;
		_num /=10;
	}
	return i;
}


void PrintArray(int arr[], int n)
{
	for(int i = n-1; i >= 0; i--)
		printf("%d ",arr[i]);
	printf("\n");
}


int main()
{
	int num = 0;
	int arrNum [ARR_SIZE] = {0};

	scanf ("%d", &num);

	int count = EnterArr(arrNum,num);
	PrintArray(arrNum,count);

	return 0;
}

