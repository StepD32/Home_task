/*

E9
Циклический сдвиг массива вправо
Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1. 

Данные на входе: 	10 целых чисел через пробел 
Данные на выходе: 	10 целых чисел через пробел сдвинутых вправо на 1 элемент циклически 

Пример №1
Данные на входе: 	4 -5 3 10 -4 -6 8 -10 1 0 
Данные на выходе: 	0 4 -5 3 10 -4 -6 8 -10 1 

Пример №2
Данные на входе: 	1 2 3 4 5 6 7 8 9 10 
Данные на выходе: 	10 1 2 3 4 5 6 7 8 9 

*/

#include <stdio.h>

#define  ARR_SIZE 12
 
void aPrint(int *arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ",arr[i]);
}



void shiftArray(int arr[], int size, int shift)
{
	int temp[size];

	for (int i = size-1 ; i >= 0 ; i--) {
		if (i+shift >= size)
			temp[i+shift-size]= arr[i];
		else
			temp[i+shift] = arr[i];
	}

	for (int i = 0; i < size; i++) {
		arr[i] = temp[i];
	}
}

 
int main()
{

int array[ARR_SIZE] = {0};
	for(int i=0; i < ARR_SIZE; i++)
		scanf("%d", &array[i]);
	shiftArray(array,ARR_SIZE,4);
	aPrint(array, ARR_SIZE);
	return 0;
} 

