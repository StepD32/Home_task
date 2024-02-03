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

<<<<<<< HEAD
=======

>>>>>>> 871df04adc7a85902ed339668847cc35beb0cec2
*/

#include <stdio.h>

#define  ARR_SIZE 10

<<<<<<< HEAD

=======
>>>>>>> 871df04adc7a85902ed339668847cc35beb0cec2
int Input (int arr[], int n) //описание функции ввода
{
	int i;
	for (i = 0; i < n; i++) //ввод массива
		scanf ("%d", &arr[i]);
	return i;
}

<<<<<<< HEAD

=======
>>>>>>> 871df04adc7a85902ed339668847cc35beb0cec2
void PrintArray(int arr[], int n)
{
	for(int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
}

<<<<<<< HEAD

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
	PrintArray(arr, ARR_SIZE);
	return 0;
} 
=======
void SortArray( int arr[], int n)
{	
	for (int i = 0; i < n-1; i++){
		for (int j = (n - 1); j > i; j--){
			if (arr[j-1]%10 > arr[j]%10){
				arr[j-1] ^= arr[j];
				arr[j] ^= arr[j-1];
				arr[j-1] ^= arr[j];
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

>>>>>>> 871df04adc7a85902ed339668847cc35beb0cec2
