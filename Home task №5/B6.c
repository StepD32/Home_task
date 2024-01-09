/*
Две одинаковые цифры рядом
Ввести целое число и определить, верно ли, что в его записи есть   две одинаковые цифры, стоящие рядом. 

Данные на входе:		Одно целое число 
Данные на выходе:	Единственное слов: YES или NO 

Пример №1
Данные на входе:	1232 
Данные на выходе:	NO 

Пример №2
Данные на входе:	1224 
Данные на выходе:	YES 

*/

#include <stdio.h>

int main(int argc, char **argv)
{
	int a,other_nums,num;
	printf("Enter number: ");
    scanf("%d", &a);
	if (a < 10){
		printf("NO ");
		return 0;
	}
	other_nums = a;
	for (int i = 0; a!=0; i++){
		num = a%10;
		if (num == other_nums){
			 printf("YES");
			 return 0;	
		}
		other_nums = num;
		a = a/10;	
	}	
	printf("NO");
}
