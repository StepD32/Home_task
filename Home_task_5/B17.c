/*
Все счастливые числа
Ввести натуральное число и напечатать все числа от 10 до введенного числа - у которых сумма цифр равна произведению цифр 

Данные на входе:	Одно натуральное число большее 10 
Данные на выходе:	Числа у которых сумма цифр равна произведению цифр через пробел в порядке возрастания. Не превосходящие введенное число. 

Пример №1
Данные на входе:	200 
Данные на выходе:	22 123 132 

Пример №2
Данные на входе:	1000 
Данные на выходе:	22 123 132 213 231 312 321 

Пример №3
Данные на входе:	22 
Данные на выходе:	22 
*/


#include <stdio.h>
 
int main(void)
{
unsigned int a,sum=0,mul=1;
	
	do
	{
		printf("Enter number:\n");
		scanf("%d",&a);
	
	}while(a<10);

	for(int i=10;i<=a;i++)
	{
		int count_i=i;	
		while(count_i != 0)
		{
			sum+=count_i%10;
			mul*=count_i%10;
			count_i/=10;
		}
		if (sum == mul)printf("%d ",i);
		sum=0;
		mul=1;
	}
	return 0;
}
