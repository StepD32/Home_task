/*
Создать прототипы (заглушки) функций:
    Вывода статистики по каждому месяцу:
        - среднемесячная температура
        - минимальная температура в текущем месяце
        - максимальная температура в текущем месяце
    Вывода статистику за год:
        - среднегодовая температура
        - минимальная температура
        - максимальная температура 
*/

//Функция добавления новых данных о температуре в массив структур по индексу.

#include "temp_api.h"

void addRecord (Sensor *date, uint32_t index, uint16_t year, uint8_t mount, uint8_t day, uint8_t hour, 
                uint8_t min, int16_t temperature)
{
    date[index].year = year;
    date[index].month = mount;
    date[index].day = day;
    date[index].hour = hour;
    date[index].min = min;
    date[index].temperature = temperature; 

}
        

int DelSensor(Sensor *date, uint16_t index, int struc_size){
    int count = struc_size - index;
    for(int i = index; i <= count; i++){
        date[i] = date[i+1];
    }
    return --struc_size;
}
//Функция печати данных из массива структур по индексу
void print(Sensor *date, uint16_t size_struct) 
{
    for(int16_t i = 0; i < size_struct; i++)
    printf("%d %04d-%02d-%02d %02d:%02d temp = %d\n",
            i,
            date[i].year,
            date[i].month,
            date[i].day,
            date[i].hour,
            date[i].min,
            date[i].temperature
    );
}

//Высчитываем среднюю температуру в месяц, проходит по всему массиву структур.
float avr_temp_month(Sensor *date, uint32_t size, Season *_season)
{
    uint32_t  count = 0;
    float sum_temp = 0;
    for(uint32_t i = 0; i < size; i++){       
       if(date[i].month == _season->mount){
            int temp = date[i].temperature;
            sum_temp += temp;             
            count++;
        }
    }
    if (!count)
        return 0;
    return sum_temp/count;
}

//Высчитываем минимальную температуру месяца, проходя по всему массиву структур.
int16_t min_temp_month(Sensor *date, uint32_t size, Season *_season)
{
    int min_temp = 99;
    for(uint32_t i = 0; i < size; i++) {
       if(date[i].month == _season->mount){    
            if (date[i].temperature < min_temp)
                min_temp = date[i].temperature;
       }
    }
    return min_temp;
}

//Высчитываем максимальную температуру месяца, проходя по всему массиву структур.
int16_t max_temp_month(Sensor* date, uint32_t size, Season *_season)
{
    int8_t  max_temp = -99;
    for(uint32_t  i = 0; i < size; i++){
       if(date[i].month == _season->mount){    
            if(date[i].temperature > max_temp)
                max_temp = date[i].temperature;
       }
    }
    return max_temp;
}

//Высчитываем среднюю температуру в месяц, проходя по всему массиву структур.
int16_t avr_temp_year(Sensor *date, uint32_t size, Season *_season)
{
    int8_t  count = 0;
    int8_t  sum_temp = 0;
    for(int i = 0; i < size; i++){       
       if(date[i].year == _season->year){
            sum_temp += date[i].temperature;             
            count++;       
       }
    }
    if (!count)
        return 0;
    return sum_temp/count;
}

int16_t min_temp_year(Sensor *date, uint32_t size, Season *_season)
{
    int min_temp = date[0].temperature;
    for(int i = 0; i < size; i++){
       if(date[i].year == _season->year){    
            if (date[i].temperature < min_temp)
                min_temp = date[i].temperature;
       }
    }
    return min_temp;
}

int16_t max_temp_year(Sensor *date, uint32_t size, Season *_season)
{
    int max_temp = 0;
    for(int i = 0; i < size; i++){
       if(date[i].year == _season->year){    
            if (date[i].temperature > max_temp)
                max_temp = date[i].temperature;
       }
    }
    return max_temp;
}

void static_output_fun(Sensor *date, uint32_t size, Season *_season)
{
   //int tmp_index = 0;
   if (_season->mount == Undefined){
        for(uint8_t i = 1; i <= 13; i++){
            _season->mount = i;
            for(uint32_t j = 0; j < size; j++){
                if(_season->mount == date[j].month && date[j].month != date[j-1].month ){
                    float avr_month = avr_temp_month(date, size, _season);	
                    int16_t min_month = min_temp_month(date, size, _season);
                    int16_t max_month = max_temp_month(date, size, _season);
                    printf("%d %2d %3d %6.2f %8d %8d\n", i, date[j].year, date[j].month, avr_month, min_month, max_month);
                } 
            }
        }
   }
}

void swap(Sensor *date, uint32_t num_one, uint32_t num_two)
{    
    Sensor temp;
    temp  = date[num_one];
    date[num_one] = date[num_two];
    date[num_two] = temp;
}

void sortByDate(Sensor *date, uint16_t num_one, uint16_t size) {
    for(int i = 0; i < size; ++i)
        for(int j =i ; j < size; ++j)
            if(dateToInt(date+i) >= dateToInt(date+j))
                swap(date,i,j);
}

uint32_t dateToInt(Sensor *date) {
    return date->year << 16 | date->month << 8 | date->day;
}

int openFile(FILE **_fp_in, const char *_input_fn)
{   
    if((*_fp_in = fopen(_input_fn, "r")) == NULL){
        perror("Error occured while opening input file");
        return 1;
    }    
    return 0;
}

uint32_t readFile(FILE **_fp_in, Sensor *date){
    uint32_t count = 0;
    int r;
    int Y, M, D, h, m, t;
    while (r = fscanf(*_fp_in, "%d;%d;%d;%d;%d;%d", &Y, &M, &D, &h, &m, &t)){
        static int line = 1;		
        if (r == -1)
            return count;
        if (r < 6){
            char s[20];
            fgets(s,sizeof(s),*_fp_in);
            printf("Error in line %d value %s", line, s);
        }
        else
            addRecord(date,count++,Y,M,D,h,m,t); 
        line++;
    }
}