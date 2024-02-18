/*
G9 ДЗ 4
Удалить повторяющиеся символы
В файле .txt строка из меленьких и больших английских букв, знаков препинания и пробелов.
Требуется удалить из нее повторяющиеся символы и все пробелы.
Результат записать в файл .txt. 

Данные на входе:    Строка из меленьких и больших английских букв, знаков препинания и пробелов.
Размер строки не более 1000 сивмолов. 
Данные на выходе:   Строка из меленьких и больших английских букв. 

Пример
Данные на входе:    abc cde def 
Данные на выходе:   abcdef   
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000


int openFile(FILE **_fp_in, const char *_input_fn)
{   
    if((*_fp_in = fopen(_input_fn, "r")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }
    
    return 0;
}

int readStringFile(FILE *_fp_in, char _str[])
{
    int _count = 0;
    char _c;
    while(((_c = getc(_fp_in)) != EOF) && (_c != '\n'))
        if (_c !=' ')
            _str[_count++] = _c;
    return _count;
}

int delCharIsString(char in_arr[], int size_in, char out_arr[])
{
    int count = 1;
    int flag = 0;
    out_arr[0] = in_arr[0];

    for(int i = 0; i < size_in; i++)
    {
        for(int j = 0; j<size_in; j++)
        {
            if(in_arr[i] == out_arr[j])
            {
                flag = 0;
                break;
            }
            else
                flag = 1;
        }
        if(flag)
            out_arr[count++] = in_arr[i];
    }
    return count;
}

void printArr(const char *_str, int size)
{
    for(int i = 0; i < size; i++)
        printf("%c",_str[i]);
}

int main()
{
    FILE *fp_in;
    const char *input_fn = "input.txt";
    char str[BUFFER_SIZE] = {0};
    char str_del[BUFFER_SIZE] = {0};
    
    if (openFile(&fp_in, input_fn)){
        printf("exit program\n");
        return 0;
    }
    
    int index = readStringFile(fp_in,str);
    fclose(fp_in);
    
    int index_del = delCharIsString(str, index, str_del);   
    
    printArr(str_del, index_del);
      
    return 0;
}
