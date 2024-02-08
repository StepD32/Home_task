/*
F6 ДЗ 4
Два одинаковых
Написать функцию и программу, демонстрирующую работу данной функции, 
которая определяет, верно ли, что среди элементов массива есть два одинаковых. 
Если ответ «да», функция возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:

int is_two_same(int size, int a[]);

Данные на входе:    Массив из целых чисел 
Данные на выходе:   Функция возвращает 1 или 0 

Пример №1
Данные на входе:    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 
Данные на выходе:   NO 

Пример №2
Данные на входе:    1 2 1 4 5 
Данные на выходе:   YES 

*/

#include <stdio.h>
#define  BUFFER_SIZE 10000

int find_equal(int _size, int _a[])
{
    int count = 0;
    for(int i = 0; i < _size; i++){
        for(int j = 0; j < _size; j++){
            if (i == j)
                continue;
            if (_a[i] == _a[j])
                count++;
            //printf("count = %d, i = %d, j = %d\n",count,i,j);
        }
        
        if (count == 1)
            return 1;
        else
            count = 0;
    }
    return 0;
}

int converNumbers(const char *_str, int *arr)
{
    int count = 0;
    int num = 0;
    
    // Находимся в цикле пока не будет конец строки
    do{
        //Собираем число из символов строки
        if((*_str >= '0') && ( *_str <= '9'))
            num = num*10+(*_str - '0');
       
        // Склеиваем число если считали пробел
        if(*_str == 0x20){
            arr[count++] = num;
            //printf("%d ", num);
            num = 0;
        }
        //Выходим из цыкла если конц строки
        if ( *_str == 0){
            arr[count++] = num;
            break;
        }
        _str++;
    } while(1);
    
    return count;
}


int main()
{
    char str[BUFFER_SIZE] = {0};
    int arr[BUFFER_SIZE] = {0};

    printf("Enter: ");
    scanf("%[^'\n']", str);
    int size = converNumbers(str, arr);
    printf("There are two identical elements %s\n",find_equal(size,arr)?"YES":"NO");
    
    return 0;
}
