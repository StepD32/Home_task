/*
G3 Практ 1
Последний номер символа
В файле .txt дана строка из 1000 символов.
Показать номера символов, совпадающих с последним символом строки.
Результат записать в файл .txt 

Данные на входе:    Строка не более 1000 символов 
Данные на выходе:   Целые числа через пробел - номера символа, который совпадает с последним символом строки. 

Пример
Данные на входе:    aabbcdb 
Данные на выходе:   2 3  
*/

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1000

int main()
{
    FILE *fp_in;
    const char *input_fn = "input.txt";
    char str[BUFFER_SIZE] = {0};
    int count = 0;
    
    if((fp_in = fopen(input_fn, "r")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }
    
    fscanf(fp_in, "%s", str);
    fclose(fp_in);    
    count = strlen(str);
    
    for(int i = 0; i<count-1;i++){
        if (str[count-1] == str[i])
            printf("%d ",i);
    }
   
    return 0;
}
