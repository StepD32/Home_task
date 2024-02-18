/*
G11
Заканчивается на a
В файле .txt дано предложение. 
Необходимо определить, сколько слов заканчиваются на букву 'а'.
Ответ записать в файл .txt. 

Данные на входе:    Строка из английских букв и пробелов не более 1000 символов. 
Данные на выходе:   Одно целое число 

Пример
Данные на входе:    Mama mila ramu 
Данные на выходе:   2   
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

int readStringFile(FILE *_fp_in){
    
    int _count = 0;
    char _c = 0;
    char _c_last = 0;
    
    //В цыкле считываем по символьно из файла
    while(1){
        _c = getc(_fp_in);
        
        // Если считали пробел или конец строки или конец файла
        // Запоминае размер максимального слова и положене в файле
        if (_c == ' ' || _c == EOF || _c == '\n'){
            if(_c_last == 'a')
                _count++;
               
            // Если добрались до конца файла или конца строки выходим из цыкла
            if (_c == EOF || _c == '\n')
                break;
        }
        _c_last = _c;
    }
    return _count;
}


int main()
{
    FILE *fp_in;
    const char *input_fn = "input.txt";

    
    if (openFile(&fp_in, input_fn)){
        printf("exit program\n");
        return 0;
    }
    
    int num = readStringFile(fp_in);
    fclose(fp_in);
    printf("Count char 'a' =  %d\n",num);
      
    return 0;
}
