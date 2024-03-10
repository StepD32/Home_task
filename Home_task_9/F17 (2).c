/*
F17 
След матрицы 
Написать функцию и программу, демонстрирующую работу данной функции, которая находит след матрицы в двумерном массиве.
Показать пример ее работы на матрице из 5 на 5 элементов. 
След матрицы - это сумма элементов на главной диагонали. 

Данные на входе: 	25 целых чисел через пробел. 
Данные на выходе: 	Одно целое число. 

Пример
Данные на входе:        1 1 1 1 1 
                        2 2 2 2 2
                        3 3 3 3 3 
                        4 4 4 4 4 
                        5 5 5 5 5 
Данные на выходе: 	15 

1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5
*/

#include <stdio.h>
#include <math.h>

#define  BUFFER_SIZE 5

void input(int n, int m, int arr[n][m])
{
    int num;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&num);
            arr[i][j] = num;        
        }
    }
}


void printArray(int n, int m, int arr[n][m])
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ",arr[i][j]);        
        }
        printf("\n");
    }
}

int matrixTrace(int n, int m, int arr[n][m])
{
    int sumTrace = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           if(i == j)
            sumTrace += arr[i][j];
        }
    }
    return sumTrace;
}


int main()
{
    int arr[BUFFER_SIZE][BUFFER_SIZE]= {{0},{0}};  

    printf("Enter: ");
    input(BUFFER_SIZE, BUFFER_SIZE,arr);
    int arrTraceSum = matrixTrace(BUFFER_SIZE, BUFFER_SIZE,arr);
    printf("Matrix trace = %d\n",arrTraceSum);
    return 0;
}
