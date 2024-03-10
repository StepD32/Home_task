/*

E8 Демо 2
Инверсия каждой трети
Считать массив из 12 элементов и выполнить инверсию для каждой трети массива. 

Данные на входе: 	12 целых чисел через пробел 
Данные на выходе: 	12 целых чисел через пробел 

Пример №1
Данные на входе: 	4 -5 3 10 -4 -6 8 -10 1 0 5 7 
Данные на выходе: 	10 3 -5 4 -10 8 -6 -4 7 5 0 1 

Пример №2
Данные на входе: 	1 2 3 4 5 6 7 8 9 10 11 12 
Данные на выходе: 	4 3 2 1 8 7 6 5 12 11 10 9 

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

void PrintArray(int arr[], int n)
{
	for(int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
}


void Inversion( int arr[], int n, int step)
{	
	int tempStep=n/step;
	for (int i = 0; i < step; i++){
		for (int j = 0; j<2; j++){
				int a = i*tempStep+j;
				int b = i*tempStep+(step-j); 
				arr[a] ^= arr[b];
				arr[b] ^= arr[a];
				arr[a] ^= arr[b];
				//printf("a = %4d b = %4d j = %4d i = %4d tempStep = %4d\n", a ,b, j, i, tempStep);
		}
	}
}


int main()
{	
	int arr[ARR_SIZE];
	printf("Enter number:\n");
	Input (arr, ARR_SIZE);
	Inversion(arr, ARR_SIZE, 3);
	PrintArray(arr, ARR_SIZE);
	return 0;
}

