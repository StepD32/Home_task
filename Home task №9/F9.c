/*
F9
Поменять местами
Написать функцию и программу, демонстрирующую работу данной функции,которая в массиве 
находит максимальный из отрицательных элементов и меняет его местами с последним элементом массива.
Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует. 
Если отрицательных элементов нет - массив не менять.

Прототип функции:
void swap_negmax_last(int size, int a[])

Данные на входе: 	Функция принимает на вход размер массива и указатель на начало массива.
Массив состоит из целых чисел. 

Пример
Данные на входе: 	1 -2 -3 -4 5 6 7 8 9 10 
Данные на выходе: 	1 10 -3 -4 5 6 7 8 9 -2 
*/

#include <stdio.h>
#define  BUFFER_SIZE 10000



int input(int arr[]){
    int i,num;
    while(scanf("%d",&num)){   
        arr[i++] = num;
        if(getchar() == 10)
            break;
    }
    return i;
}

void printArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void find(int _a[],int _size)
{
    int minNegativ = 0;
    int pos = 0;
    
    for(int i = 0; i < _size; i++){
        if (_a[i] < minNegativ)
            minNegativ = _a[i];            
    }
    
    for (int i = 0; i < _size; i++){
        if(_a[i] > minNegativ && _a[i] < 0)
            minNegativ = _a[i], pos=i; 
    } 
    _a[pos] ^= _a[_size-1];
    _a[_size-1] ^= _a[pos];
    _a[pos] ^= _a[_size-1];
}


int main()
{
    int arr[BUFFER_SIZE] = {0};  

    printf("Enter: ");
    int count = input(arr);
    find(arr,count);
    printArray(arr, count);

    return 0;
}
