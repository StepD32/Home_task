/*
Вычислить cos
Составить функцию, которая вычисляет косинус как сумму ряда (с точностью 0.001)

cos(x) = 1 - x2/2! + x4/4! - x6/6! + ... 
(x в радианах)
float cosinus(float x)

Данные на входе: 	Целое число от 0 до 90 
Данные на выходе: 	Вещественное число в формате "%.3f" 

Пример
Данные на входе: 	60 
Данные на выходе: 	0.500 
*/

#include <stdio.h>
#include <math.h>
 
const float PI = 3.1415926535;
	
unsigned long fact(int num)
{
	unsigned long mul = 1;
	for(int i=1; i<=num; i++)
	{
		mul *= i; 
	}
	return mul;
}

float cosx(float x)
{
	float Xn = x;
	float sum = 1;
	int i = 2;

	do
	{
		
		sum += Xn;
		Xn *=-1*(pow(x,i)/fact(i));
		i += 2;
	}
	while (fabs(Xn) > 0.001);
	printf("i=%d\n",i);
	return sum;
}

int main(void)
{
	float x;
	printf("Enter degrees:\n");
	scanf("%f",&x);
	x *= PI/180.0;
	printf("%.3f",cosx(x));
	return 0;
}

