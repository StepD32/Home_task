/*
F2 ДЗ 2

Четные в начало
Написать функцию и программу, демонстрирующую работу данной функции, которая ставит в начало массива все четные элементы,
а в конец – все нечетные. Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:
void sort_even_odd(int n, int a[])

Данные на входе: 	Функция принимает на вход целые числа 
Данные на выходе: 	Отсортированный исходный массив 

Пример №1
Данные на входе: 	20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 
Данные на выходе: 	20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3 1 

Пример №2
Данные на входе: 	1 0 1 0 1 
Данные на выходе: 	0 0 1 1 1 

*/

#include <stdio.h>

#define  BUFFER_SIZE 20

int isDigit(char c) // проверяем является ли символ цифрой
{
    return ((c>='0')&&(c<='9'));
}

int InputGet(int arr[], int n)
{
    int i;
    char c;
    while((c=getchar())!='\n'){
        if(isDigit(c)){
            int number=0;
            do{
                number=number*10+c-'0';
                c=getchar();
            }
            while(isDigit(c));
            arr[i++] = number;
            if(c=='\n')
                break;
        }
    }
    return i;
}



void SortEven(int arr[], int n)
{
    int arr_not_even[n];
    int arr_even[n];
    int count_even = 0;
    int count_not_even = 0;

    for(int i = 0; i < n; ++i){
        if (!(arr[i]%2)){
            arr_even[count_even] = arr[i];
            count_even++;
        }
        else{
            arr_not_even[count_not_even] = arr[i];
            count_not_even++;
        }
    }

    for(int j = 0; j < count_even; j++)
        arr[j] = arr_even[j];

    for(int j = count_even; j < n; j++)
        arr[j] = arr_not_even[j-count_even];
}


void Print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ",arr[i]);
}

int main()
{
    int buffer[BUFFER_SIZE] = {0};

    printf("Enter number: ");
    int size = InputGet(buffer,BUFFER_SIZE);
    printf("Buffer size = %d\n",size);
    SortEven(buffer,size);
    Print(buffer,size);

    return 0;
}
