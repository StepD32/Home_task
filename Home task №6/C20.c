/*
Скобки

Проверить строку состоящую из скобок "(" и ")" на корректность. 

Данные на входе: 	На вход подается строка состоящая из символов '(', ')' и заканчивающаяся символом '.'. Размер строки не более 1000 символов. 
Данные на выходе: 	Необходимо напечатать слово YES если скобки расставлены верно и NO в противном случае. 

Пример №1
Данные на входе: 	(()()). 
Данные на выходе: 	YES 

Пример №2
Данные на входе: 	()(. 
Данные на выходе: 	NO 

*/

#include <stdio.h>

int digit_to_num(char c)
{
    if (c =='(')
        return 1;
    if (c ==')')
        return 2;
    return 0;
}

int main(void   )
{
int open = 0, close = 0;
char input;
    while (1)
    {
        scanf("%c", &input);
        if (input == '.')
            break;
        switch (digit_to_num(input))
        {
            case 1:
                open++;
            break;
            case 2:
                close++;
            break;
        }
    }
    if ((open == close) && open!=0 && close!=0)
         printf("YES\n");
    else
         printf("NO\n");
    return 0;
}
