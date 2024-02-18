/*
G12
Разобрать на слова
В файле .txt дано предложение требуется разобрать его на отдельные слова.
Напечатать каждое слово на отдельной строке в файл .txt. 

Данные на входе:    Одна строка из английских букв и пробелов не более 1000 символов. 
Данные на выходе:   Каждое слово на отдельной строке 

Пример
Данные на входе:    Mama mila ramu 
Данные на выходе:   Mama mila ramu  
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000


int openFileRead(FILE **_fp_in, const char *_input_fn)
{   
    if((*_fp_in = fopen(_input_fn, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
        
    return 0;
}


int openFileNewWrite(FILE **_fp_in, const char *_input_fn)
{   
    if((*_fp_in = fopen(_input_fn, "w")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }  
      
    return 0;
}


int writeStrFile(FILE **_fp_in, const char *_input_fn , const char* _str)
{
    int len = strlen(_str);
    char tmp_str[len];
    int index = 0;
    while(1)
    {
        if(*_str != ' ' && *_str != '\0')
            tmp_str[index++] = *_str;
        else
        {
            tmp_str[index++] = '\0';
            printf("%s\n",tmp_str);            
            index = 0;
            fputs(tmp_str, *_fp_in);
            fputs("\n", *_fp_in);            
            if(*_str == '\0')
                break;            
        }
        _str++;
    }
    
    return 0;
}

int main()
{
    FILE *fp_in;
    const char *input_fn = "input.txt";
    char str[BUFFER_SIZE] = {0};
    
    if (openFileRead(&fp_in, input_fn))
    {
        printf("exit program\n");
        return 0;
    }
    
    fgets(str, sizeof(str), fp_in);
    fclose(fp_in);
    
    if (openFileNewWrite(&fp_in, input_fn))
    {
        printf("exit program\n");
        return 0;
    }

    writeStrFile(&fp_in, input_fn, str);
    fclose(fp_in);
    
    
    return 0;
}
