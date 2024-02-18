/*
G10
Самое длинное слово
В файле .txt дана строка слов, разделенных пробелами.
Найти самое длинное слово и вывести его в файл .txt.
Случай, когда самых длинных слов может быть несколько, не обрабатывать. 

Данные на входе:    Строка из английских букв и пробелов. Не более 1000 символов. 
Данные на выходе:   Одно слово из английских букв. 

Пример
Данные на входе:    Hello beautiful world 
Данные на выходе:   beautiful  
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000


int openFile(FILE **_fp_in, const char *_input_fn){
   
    if((*_fp_in = fopen(_input_fn, "r")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }
    
    return 0;
}

//Данные на входе:    Hello beautiful world 
//Данные на выходе:   beautiful  

void readStringFile(FILE *_fp_in){
    
    int _count = 0;
    int _index = 0;
    char _c;
    int _max = 0;
    int _max_index = 0;
    int size = 0;
    
    //В цыкле считываем по символьно из файла
    while(1){
        _c = getc(_fp_in);
        
        // Если считали пробел или конец строки или конец файла
        // Запоминае размер максимального слова и положене в файле
        if (_c == ' ' || _c == EOF || _c == '\n'){
            size = _count - _index;
            _index = _count;
            if (size > _max){
                _max = size;
                _max_index = _count;
            }
            
            // Если добрались до конца файла или конца строки выходим из цыкла
            if (_c == EOF || _c == '\n')
                break;
        }
        _count++;
    }
    
    //Перходим по индексу к концу максимального слова в файле и считываем максимальнео слово 
    if (fseek (_fp_in,_max_index - _max+1,SEEK_SET) == 0)   
        while(_max--)
            printf("%c",getc(_fp_in));
}


int main()
{
    FILE *fp_in;
    const char *input_fn = "input.txt";

    
    if (openFile(&fp_in, input_fn)){
        printf("exit program\n");
        return 0;
    }
    
    readStringFile(fp_in);
    fclose(fp_in);
      
    return 0;
}
