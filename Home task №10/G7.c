/*
G7 Практ 2
Количество букв
В файле .txt считать символьную строку, не более 10 000 символов. 
Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке.
Учитывать только английские буквы. 
Результат записать в файл .txt. 

Данные на входе:    Строка состоящая из английских букв, цифр, пробелов и знаков препинания. 
Данные на выходе:   Два целых числа. Количество строчных букв и количество заглавных букв. 

Пример №1
Данные на входе:    aabbAB 
Данные на выходе:   4 2 

Пример №2
Данные на входе:    HELLO WORLD 
Данные на выходе:   0 10  
*/

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10000

int main()
{
    FILE *fp_in;
    const char *input_fn = "input.txt";
    char str[BUFFER_SIZE] = {0};
    char c;
    int count = 0;
    int small = 0;
    int big = 0;
    
    if((fp_in = fopen(input_fn, "r")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }
    
    while(((c = getc(fp_in)) != EOF) && (c != '\n'))
        str[count++] = c;
    str[count] = '\0';
    fclose(fp_in);    
           
    for(int i = 0; i<count;i++){
        if (str[i] >= 'a' && str[i] <='z')
            small++;
        if (str[i] >= 'A' && str[i] <='Z')
            big++;
    }
   
    printf("%d %d", small, big);
    return 0;
}
