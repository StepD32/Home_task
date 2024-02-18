/*
G5 ДЗ 2
Заменить a на b
В файле .txt дана символьная строка не более 1000 символов. 
Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные.
Результат записать в .txt. 

Данные на входе:    Строка из маленьких и больших английских букв, знаков препинания и пробелов. 
Данные на выходе:   Строка из маленьких и больших английских букв, знаков препинания и пробелов. 

Пример
Данные на входе: 	aabbccddABCD 
Данные на выходе: 	bbaaccddBACD 
*/

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1000

int main()
{
    FILE *fp_in, *fp_out;
    const char *input_fn = "input.txt";
    const char *output_fn = "output.txt";
    char str_one[BUFFER_SIZE] = {0};
    char str_two[BUFFER_SIZE] = {0};
    
    if((fp_in = fopen(input_fn, "r")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }
    
    fscanf(fp_in, "%s", str_one);
    fclose(fp_in);     
       
    int len_str_one = strlen(str_one);  

    for(int i = 0; i < len_str_one; i++){
        if(str_one[i] == 'a'){
            str_two[i] = 'b';
            continue;
        }
        if(str_one[i] == 'b'){
            str_two[i] = 'a';
            continue;
        }
        if(str_one[i] == 'A'){
            str_two[i] = 'B';
            continue;
        }
        if(str_one[i] == 'B'){
            str_two[i] = 'A';
            continue;
        }
        str_two[i] = str_one[i];
    }
    
    printf("%s\n",str_one);
    printf("%s\n",str_two);    
        
    if((fp_out = fopen(output_fn, "w")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }
    
    fprintf(fp_out,"%s",str_two);
    fclose(fp_out);    
    
    return 0;
}
