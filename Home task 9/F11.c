/*
F11 Практ 3
Сумма минимальна
Написать функцию и программу, демонстрирующую работу данной функции.
Дан целочисленный массив из 30 элементов.
Элементы массива могут принимать произвольные целые значения помещающиеся в int.
Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива, сумма которых минимальна. 

Данные на входе: 	Последовательность из 30 целых чисел через пробел 
Данные на выходе: 	Два целых числа через пробел 

Пример
Данные на входе: 	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 
Данные на выходе: 	0 1 
*/

#include <stdio.h>
#include <limits.h>
#define  BUFFER_SIZE 30



int input(int arr[], int _size){
    int i = 0; 
    int num;
    while(i < _size){   
        scanf("%d",&num);
        arr[i++] = num;        
    }
    return i;
}

void printArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
void find(int _a[],int _size)
{
    int sum = INT_MAX;
    int index_one = 0;
    int index_two = 0;
    for(int i = 0; i < _size; i++){
        for(int j = 0; j < _size-1;j++){
            if (i == j){
                //printf("%d == %d\n",i,j);
                continue;
            }
            
            int sum_index = _a[i] + _a[j];  
            //printf("sum_idex = %d, _a[%d] = %d, _a[%d] = %d\n",sum_index, i, _a[i], j, _a[j]);  
            if(sum > sum_index){
                //printf("sum = %d, sum_index = %d\n",sum,sum_index); 
                sum = sum_index;
                index_one = i;
                index_two =j;
                
            }
        }
    }
    printf("%d %d\n",index_one,index_two);
}


int main()
{
    int arr[BUFFER_SIZE] = {0};  

    printf("Enter: ");
    int count = input(arr,BUFFER_SIZE);
    find(arr,count);
    //printArray(arr, count);

    return 0;
}
