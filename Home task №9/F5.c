/*
F5 ДЗ 3
Максимум в массиве
Написать функцию и программу, демонстрирующую работу данной функции, которая находит максимальный элемент в массиве. 

Прототип функции:
int find_max_array(int size, int a[])

Данные на входе: 	Массив состоящий из целых чисел. Первый аргумент, размер массива, второй аргумент адрес нулевого элемента. 
Данные на выходе: 	Одно целое число 

Пример №1
Данные на входе: 	773 307 371 548 531 765 402 27 573 591 217 859 662 493 173 174 125 591 324 231 130 394 573 65 570 258 343 3 586 14 785 296 140 726 598 262 807 794 510 465 66 895 182 218 302 34 205 252 687 660 952 737 2 32 310 680 36 139 346 139 489 217 767 544 158 774 883 154 802 136 569 377 867 423 224 176 118 660 513 734 45 978 983 749 909 601 270 147 433 737 789 304 842 769 815 503 190 399 3. 
Данные на выходе: 	983 

*/

#include <stdio.h>

#define  BUFFER_SIZE 10000



int find_max_array(int _size, int _a[])
{
    int max = 0;
    for(int i = 0; i < _size; i++){
        if(max < _a[i])
            max = _a[i];
    }
    return max;
}

int converNumbers(const char *_str, int *arr)
{
    int count = 0;
    int num = 0;
    
    // Находимся в цикле пока не будет конца строки
    do{
        //Собираем число из символов строки до символа пробела или перевода коредки
        if((*_str >= '0') && ( *_str <= '9'))
            num = num*10+(*_str - '0');
       
        // Склеиваем число до пробела или конца строки
        if(*_str == 0x20 || *_str == 0){
            arr[count++] = num;
            //printf("%d ", num);
            num = 0;
        }
        //Выходим из цыкла если конц строки
        if ( *_str == 0)
            break;
            
        _str++;
       
    } while(1);
     
    return count;
}


int main()
{
    char str[BUFFER_SIZE];
    int arr[BUFFER_SIZE] = {0};

    printf("Enter: ");
    scanf("%[^'\n']", str);
    int size = converNumbers(str, arr);
    printf("Maximum in array = %d \n",find_max_array(size,arr));
    
    return 0;
}
