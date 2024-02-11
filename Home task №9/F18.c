/*
F18
Массив максимумов
Написать функцию и программу, демонстрирующую работу данной функции.
Дана целочисленная квадратная матрица 10 х 10. 
Реализовать алгоритм вычисления суммы максимальных элементов из каждой строки.
Напечатать значение этой суммы. 
Предполагается, что в каждой строке такой элемент единственный.
Реализовать функцию поиска максимума в строке из 10 элементов 

Данные на входе: 	10 строк состоящих из 10 целых чисел через пробел. 
Данные на выходе: 	Одно целое число 

Пример
Данные на входе: 	61 75 55 2 35 34 77 93 28 49 11 34 22 78 19 14 67 67 11 0 72 39 23 53 92 51 60 34 71 63 14 27 72 6 0 79 98 56 30 15 31 16 3 4 95 59 25 17 11 20 5 93 21 61 96 30 79 38 73 40 89 4 66 19 36 99 67 67 92 36 87 54 7 35 40 43 44 46 4 69 98 57 20 75 9 66 85 9 39 31 8 90 94 25 12 30 18 10 23 15 
Данные на выходе: 	930 
*/

#include <stdio.h>
#include <math.h>

#define  BUFFER_SIZE 10

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
    int sumMax = 0;
    int max_line = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(max_line < arr[i][j]){
                max_line = arr[i][j]; 
               // printf("Max line %d\n",arr[i][j]); 
            }
        }
        sumMax += max_line;
        max_line = 0;
    }
    return sumMax;
}


int main()
{
    int arr[BUFFER_SIZE][BUFFER_SIZE]= {{0},{0}};  

    printf("Enter: ");
    input(BUFFER_SIZE, BUFFER_SIZE,arr);
    printf("\n");
    printArray(BUFFER_SIZE, BUFFER_SIZE,arr);    
    printf("\n");
    int arrTraceSum = matrixTrace(BUFFER_SIZE, BUFFER_SIZE, arr);
    printf("Sum max line = %d\n",arrTraceSum);
    return 0;
}
