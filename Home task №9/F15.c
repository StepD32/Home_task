/*
F15
Больше по модулю
Написать функцию и программу, демонстрирующую работу данной функции, 
которая определяет в массиве, состоящем из положительных и отрицательных чисел,
 сколько элементов превосходят по модулю максимальный элемент. 
 Прототип функции
int count_bigger_abs(int n, int a[]);

Данные на входе: 	Функция получает размер массива и массив целых чисел 
Данные на выходе: 	Функция возвращает целое число раное количеству элементов
превосходящих по модулю максимальный элемент. 

Пример
Данные на входе: 	1 -20 3 4 -50 6 7 8 9 10 
Данные на выходе: 	2  
*/

#include <stdio.h>
#include <math.h>

#define  BUFFER_SIZE 30

int input(int arr[]){
    int i,num;
    while(scanf("%d",&num)){   
        arr[i++] = num;
        if(getchar() == 10)
            break;
    }
    return i;
}

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int count_bigger_abs(int size, int a[]){
    int max_i = 0;
    int count = 0;
    for( int i = 0; i < size; i++)
        if( max_i < a[i])
            max_i = a[i];
    //printf("max_i = %d\n ", max_i);
    for ( int i = 0; i < size; i++)
        if(abs(a[i]) > max_i)
            count++;
    return count;
}


int main()
{
    int arr[BUFFER_SIZE] = {0};  

    printf("Enter: ");
    int count = input(arr);    
    printf("Number of numbers by module = %d\n",count_bigger_abs(count,arr));

    return 0;
}
