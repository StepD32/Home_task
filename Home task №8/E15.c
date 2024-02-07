/*
Положительные и отрицательные
Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: 
в одни помещать только положительные, во второй - только отрицательные. 
Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов. 

Данные на входе: 	10 целых чисел через пробел. 
Данные на выходе: 	Сперва положительные числа, потом отрицательыне числа, через пробел. 

Пример
Данные на входе: 	5 -4 0 1 4 -3 -3 3 0 2 
Данные на выходе: 	5 1 4 3 2 -4 -3 -3 

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
    for(int i = 0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int SelectArr(int _arr[], int _arr_pos[], int n)
{
    int _count = 0;
    
    for(int i = 0; i < n; i++){
        if (_arr[i] > 0 ){
            _arr_pos[_count++] = _arr[i];
          
        }
    }
    
    for(int i = 0; i < n-1; i++){
        if (_arr[i] < 0 ){
            _arr_pos[_count++] = _arr[i];
        }
    }
    return _count;
}

int main()
{
    int arr[ARR_SIZE] = {0};
    int posArr[ARR_SIZE] = {0};
    int count = 0;
    
    printf("Enter number: ");
    Input (arr, ARR_SIZE);
    count = SelectArr(arr, posArr, ARR_SIZE);
    printf("Sort array: ");
    PrintArray(posArr, count);
    
	return 0;
}

