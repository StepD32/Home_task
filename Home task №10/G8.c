/*
Числа в массив
В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы.
Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
Вывести массив по возрастанию в файл .txt. 

Данные на входе:    Строка из английских букв, цифр и знаков препинания 
Данные на выходе: 	Последовательность целых чисел отсортированная по возрастанию 

Пример
Данные на входе:    data 48 call 9 read13 blank0a 
Данные на выходе:   0 9 13 48  
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

int readDigitIsFile(FILE *_fp_in, char _str[], int _arr_num[])
{
    int _num = 0;
    int _count = 0;
    int _flag = 0;
    int _count_num = 0;
    char _c;
    
    while(((_c = getc(_fp_in)) != EOF) && (_c != '\n')){
        if (_c >= '0' && _c <='9'){
            _flag = 1;
            _str[_count++] = _c;
        }
        else{
            if (!_flag)
                continue;
            else{
                _num = atoi(_str);
                _flag = 0; 
                memset(_str,0,_count);
                _count = 0;
                _arr_num[_count_num++] = _num;
            }
        }  
        
    }
    return _count_num;
}

void Sort(int* arr, int size)
{
  for (int i = 0; i < size - 1; i++){
    for (int j = (size - 1); j > i; j--){
      if (arr[j - 1] > arr[j]){
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void printArr(int* arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ",arr[i]);

}

int main()
{
    FILE *fp_in;
    const char *input_fn = "input.txt";
    char str[BUFFER_SIZE] = {0};
    int arr_num[BUFFER_SIZE] = {0};
    int count_num = 0;
    
    //printf("before open %p\n",fp_in);
    
    //if((fp_in = fopen(input_fn, "r")) == NULL){
        //perror("Error occured while opening input file!");
        //return 1;
    //}
    
    if (openFile(&fp_in, input_fn)){
        printf("exit program\n");
        return 0;
    }
    
    count_num = readDigitIsFile(fp_in, str, arr_num);   
    fclose(fp_in);
    Sort(arr_num,count_num); 
    printArr(arr_num,count_num);
      
    return 0;
}
