/*

E7 Практик 2
Инверсия половинок
Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива. Необходимо изменить считанный массив и напечатать его одним циклом. 

Данные на входе: 		10 целых элементов массива через пробел. 
Данные на выходе: 		10 целых элементов массива через пробел. 

Пример №1
Данные на входе: 		4 -5 3 10 -4 -6 8 -10 1 0 
Данные на выходе: 		-4 10 3 -5 4 0 1 -10 8 -6 

Пример №2
Данные на входе: 		1 2 3 4 5 6 7 8 9 10 
Данные на выходе: 		5 4 3 2 1 10 9 8 7 6 


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
	for(int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
}

void Inversion( int arr[], int n)
{	
	int tempAra[n];

	for (int i = (n/2)-1, j = 0; i >=0; i--,j++){
		tempAra[j] = arr[i];
	}

	for (int i = n-1, j = (n/2) ; i >=(n/2); i--,j++){
		tempAra[j] = arr[i];
	}
	
	for(int i = 0; i < n; i++){
		arr[i]=tempAra[i];
	}
}

void Inversion2( int arr[], int n)
{	
	for (int i = (n/2)-1, j = 0; i >=0; i--,j++){
		if(i-j >0){
			arr[j] ^= arr[i];
			arr[i] ^= arr[j];
			arr[j] ^= arr[i];
			
		}
	}

	for (int i = n-1, j = (n/2) ; i >=(n/2); i--,j++){
		if(i-j >0){
			arr[j] += arr[i];
			arr[i] = arr[j] - arr[i];
			arr[j] -= arr[i];
			
		}
	}
}


int main()
{	
	int arr[ARR_SIZE];
	printf("Enter number: ");
	Input (arr, ARR_SIZE);
	Inversion2(arr, ARR_SIZE);
	PrintArray(arr, ARR_SIZE);
	return 0;
}

