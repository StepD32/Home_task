/*
F4 Практ 1
Цифры в строке
Написать функцию и программу, демонстрирующую работу данной функции.
Вывести в порядке возрастания цифры, входящие в строку. Цифра - количество. 
Функция должно строго соответствовать прототипу:

void print_digit(char s[])

Данные на входе: 	Строка из английских букв, пробелов, знаков препинания и цифр 
Данные на выходе: 	Функция должна принимать на вход строку и выводить на печать по формату: 
Цифра пробел количество. 

Пример
Данные на входе: 	Hello123 world77. 
Данные на выходе: 	1 1 2 1 3 1 7 2 

*/

#include <stdio.h>

#define  BUFFER_SIZE 10000
#define  BUFFER_DIG 10


int inputGetConsol(char *s)
{
	int i = 0;
	char c;
	for(i = 0; (c = getchar()) != '\n'; i++)
	{
		if(c =='\n')
			break;
		*s++ = c;
	}
	return i;
}

void count_digits(char n[], int* res)
{
	for (int i=0; n[i]!=0; i++)
		res[n[i] - '0']++;
}

void printDigist(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		if (arr[i] > 0)
			printf("%d %d ", i, arr[i]);
}

void sortEven(int arr[], int n)
{
	int arr_not_even[n];
	int arr_even[n];
	int count_even = 0;
	int count_not_even = 0;

	for(int i = 0; i < n; ++i)
	{
		if (!(arr[i]%2))
		{
			arr_even[count_even] = arr[i];
			count_even++;
		}
		else
		{
			arr_not_even[count_not_even] = arr[i];
			count_not_even++;
		}
	}

	for(int j = 0; j < count_even; j++)
		arr[j] = arr_even[j];

	for(int j = count_even; j < n; j++)
		arr[j] = arr_not_even[j-count_even];
}

void printString(char arr[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%c",arr[i]);
}

void printStringScanf(char str[])
{
	int i = 0;
	while(str[i])
		printf("%c",str[i++]);
	printf("\n");
}

int main()
{

	char str[BUFFER_SIZE] = {0};
	int arr_dig[BUFFER_DIG] = {0};

	printf("Enter string: ");
	
	//inputGetConsol(str);
		
	scanf("%[^'\n']", str);
	//printStringScanf(str);
	
	count_digits(str, arr_dig);
	printDigist(arr_dig,BUFFER_DIG);
	

	return 0;
}
