/*

E10 ДЗ 3
Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента. 

Данные на входе: 	12 целых чисел через пробел 
Данные на выходе: 	12 целых чисел через пробел 

Пример №1
Данные на входе: 	4 -5 3 10 -4 -6 8 -10 1 0 5 7 
Данные на выходе: 	1 0 5 7 4 -5 3 10 -4 -6 8 -10 

Пример №2
Данные на входе: 	1 2 3 4 5 6 7 8 9 10 11 12 
Данные на выходе: 	9 10 11 12 1 2 3 4 5 6 7 8 


*/

#include <stdio.h>

#define  ARR_SIZE 12
#define  SHIFT -4

int Input (int arr[], int n) //описание функции ввода
{
	int i;

	for (i = 0; i < n; i++) //ввод массива
		scanf ("%d", &arr[i]);
	return i;
}


void PrintArray(int arr[], int n)
{
	for(int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
}


void shiftArray(int arr[], int size, int shift)
{
	int temp[size];

	for (int i = size-1; i >= 0; i--){
		if (i+shift >= size)
			temp[i+shift-size]= arr[i];
		else
			temp[i+shift] = arr[i];
	}

	for (int i = 0; i < size; i++){
		arr[i] = temp[i];
	}
}

 
int main()
{
    int arr[ARR_SIZE];
	printf("Enter number:\n");
	Input (arr, ARR_SIZE);
	shiftArray(arr,ARR_SIZE,SHIFT);
	PrintArray(arr, ARR_SIZE);
	return 0;
} 

