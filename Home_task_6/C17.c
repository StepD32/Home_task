/*
Сумма цифр равна произведению

Составить логическую функцию, которая определяет, верно ли, что в данном числе сумма цифр равна произведению.

int is_happy_number(int n)

Данные на входе: 	Целое не отрицательное число 
Данные на выходе: 	YES или NO 

Пример №1
Данные на входе: 	123 
Данные на выходе: 	YES 

Пример №2
Данные на входе: 	528 
Данные на выходе: 	NO 

*/

#include <stdio.h>


int is_happy_number(unsigned int a)
{
unsigned int sum = 0, mul = 1;
	for(int i=0; a!=0;i++)
	{
		unsigned int temp_dev = a%10;
		sum +=temp_dev;
		mul *=temp_dev;
		a/=10;
		
	}
    return sum == mul ? 0 : 1;
}

int main(void)
{
unsigned int a;
	printf("Enter number: ");
	scanf("%d",&a);
	if (a>0)
	{
		printf("The sum of the digits is equal to the product: ");
		is_happy_number(a)!=0 ? printf("NO\n"):printf("YES\n");
	}
	return 0;
}
