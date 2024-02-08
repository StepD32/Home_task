/*
F8 Практ 2
Пропущенное число
Написать функцию и программу, демонстрирующую работу данной функции.
В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1) в произвольном порядке, 
но одно из чисел пропущено (остальные встречаются ровно по одному разу). N не превосходит 1000. 
Последовательность заканчивается числом 0. Определить пропущенное число. 

Данные на входе: 	Последовательность целых чисел от M до N. M, N не превосходит 1000. 
Данные на выходе: 	Одно целое число 

Пример №1
Данные на входе: 	2 3 1 4 7 6 9 8 10 0 
Данные на выходе: 	5 

Пример №2
Данные на входе: 	41 40 39 38 37 36 34 33 32 31 50 49 48 47 46 45 44 43 42 30 0 
Данные на выходе: 	35 

*/

#include <stdio.h>
#define  BUFFER_SIZE 10000



int Input(int arr[]){
    int i,num;
    while(scanf("%d",&num)==1){
        if (num == 0)
            break;
        arr[i++] = num;
    }
    return i;
}

void PrintArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}


void SortArray( int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = (n - 1); j > i; j--)
        {
            if (arr[j-1] > arr[j])
            {
                arr[j-1] ^= arr[j];
                arr[j] ^= arr[j-1];
                arr[j-1] ^= arr[j];
            }
        }
    }
}

int find(int _a[],int _size)
{
    int num = 0;
    for(int i = 0; i < _size-1; i++){
        num = _a[i];
        if(!(_a[i+1] == ++num))
            return num;
    }
    return 0;
}

int main()
{
    int arr[BUFFER_SIZE] = {0};

    printf("Enter: ");
    int size = Input(arr);
    SortArray(arr,size);
    printf("Missing number = %d \n",find(arr,size));

    return 0;
}
