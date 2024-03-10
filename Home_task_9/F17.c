/*
F17 
След матрицы 
Написать функцию и программу, демонстрирующую работу данной функции,
которая находит след матрицы в двумерном массиве.
Показать пример ее работы на матрице из 5 на 5 элементов. 
След матрицы - это сумма элементов на главной диагонали. 

Данные на входе: 		25 целых чисел через пробел. 
Данные на выходе: 	Одно целое число. 

Пример
Данные на входе: 		1 1 1 1 1 
                        2 2 2 2 2
                        3 3 3 3 3 
                        4 4 4 4 4 
                        5 5 5 5 5 
Данные на выходе: 	15  
*/

#include <stdio.h>
#include <math.h>

#define  BUFFER_SIZE 5

void input(int arr[n][m], int _count){
    int i = 0;
    int j = 0;
    int count = 0; 
    int m = 0;
    for (int i = 0; i < n; ++i){ 
        for (int j = 0; j < m; ++j)
            cout << A[i][j] << " ";
        cout << endl;

    }
}

void getColor(int a[]){
    if ( (a[0]+a[1]) % 2 != 0)
        printf("WHITE\n");
    else
        printf("BLACK\n");
}


int main()
{
    int arr[BUFFER_SIZE][BUFFER_SIZE] = {0};  

    printf("Enter: ");
    input(arr, 25);  
    //getColor(arr);    
    return 0;
}
