/*
Цифры по возрастанию

Составить функцию логическую функцию, которая определяет, верно ли, что в заданном числе все цифры стоят по возрастанию. Используя данную функцию решить задачу.

int grow_up(int n)

Данные на входе: 	Одно целое не отрицательное число 
Данные на выходе: 	YES или NO 

Пример №1
Данные на входе: 	258 
Данные на выходе: 	YES 

Пример №2
Данные на входе: 	528 
Данные на выходе: 	NO 
*/

#include <stdio.h>


int grow_up(unsigned int a)
{
unsigned int other_nums = a;
    for(int i=0; a!=0;i++)
    {   
    int temp_dev = a%10;
        if (temp_dev < other_nums)        
            a/=10; 
        else 
            return -1;
        other_nums = temp_dev;
    }
    return 0;
}

int main(void)
{
unsigned int a;
    printf("Enter number:\n");
    scanf("%d",&a);
    printf("Numbers are in ascending order ");
    grow_up(a)!=0 ? printf("NO\n"):printf("YES\n");
    return 0;
}
