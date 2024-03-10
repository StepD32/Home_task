/*
G4 ДЗ 1
По одному разу
В файле .txt даны два слова не более 100 символов каждое, разделенные одним пробелом. 
Найдите только те символы слов, которые встречаются в обоих словах только один раз. 
Напечатайте их через пробел в файл .txt в лексикографическом порядке. 

Данные на входе:    Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов. 
Данные на выходе:   Маленькие английские буквы через пробел. 

Пример №1
Данные на входе:    hello world 
Данные на выходе:   o 


Данные на входе:    aabcd bcef 
Данные на выходе:   b c  
*/

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int main()
{
    FILE *fp_in;
    const char *input_fn = "input.txt";
    char str_one[BUFFER_SIZE] = {0};
    char str_two[BUFFER_SIZE] = {0};

    
    if((fp_in = fopen(input_fn, "r")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }
    
    fscanf(fp_in, "%s %s", str_one, str_two);
    fclose(fp_in);    
    int len_str_one = strlen(str_one);
    int len_str_two = strlen(str_two);
    

    for(int i = 0; i < len_str_one; i++){
        for(int j = 0; j < len_str_two; j++){
            if (str_one[i] == str_two[j]){                
                if (str_one[i] != str_one[i+1] && str_one[i] != str_one[i-1])
                    printf("%c ", str_one[i]);
            }
        }
    }
    
    //printf("str_one =%s, str_two = %s",str_one, str_two);
    
    
    return 0;
}
