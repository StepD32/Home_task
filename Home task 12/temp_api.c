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

//Функция добавления новых данных о температоруре в массив структор по индексу.

#include "temp_api.h"


uint8_t addRecord (Sensor *date, uint8_t index, uint16_t year, uint8_t mount, uint8_t day, uint8_t hour, 
                uint8_t min, int8_t temperature)
{
    date[index].year = year;
    date[index].month = mount;
    date[index].day = day;
    date[index].hour = hour;
    date[index].min = min;
    date[index].temperature = temperature; 
    return index;
}

int AddInfo(Sensor* info)
{   
    int num = 0;
    addRecord(info,num++,2021,4,10,10,50,3);
    addRecord(info,num++,2021,8,9,10,50,15);
    addRecord(info,num++,2021,8,16,10,50,18);
    addRecord(info,num++,2021,8,6,7,40,35);
    addRecord(info,num++,2021,8,1,7,10,20);
    addRecord(info,num++,2021,12,20,10,30,-20);
    return num;
}            

//Функция печати данный из массива структор по индексу 
void print(Sensor *date, int index) 
{
    printf("%d %04d-%02d-%02d %02d:%02d t = %3d\n",
            index,
            date[index].year,
            date[index].month,
            date[index].day,
            date[index].hour,
            date[index].min,
            date[index].temperature
    );
}

//Высчитываем среднию температуру в месяцаы, проходя по всему массиву структор.
int8_t avr_temp_month(Sensor *date, uint8_t size, Season *m)
{
    int8_t  count = 0;
    int8_t  sum_temp = 0;
    for(int i = 0; i < size; i++){       
       if(date[i].month == m->mount){
            sum_temp += date[i].temperature;             
            count++;
        }
    }
    if (!count)
        return 0;
    return sum_temp/count;
}

//Высчитываем минимальную температуру месяца, проходя по всему массиву структор.
int8_t min_temp_month(Sensor *date, uint8_t size, Season *m)
{
    int min_temp = 99;
    for(int i = 0; i < size; i++) {
       if(date[i].month == m->mount){    
            if (date[i].temperature < min_temp)
                min_temp = date[i].temperature;
       }
    }
    return min_temp;
}

//Высчитываем максимальную температуру месяца, проходя по всему массиву структор.
int8_t max_temp_month(Sensor* date, uint8_t size, Season *m)
{
    int8_t  max_temp = -99;
    for(uint8_t  i = 0; i < size; i++){
       if(date[i].month == m->mount){    
            if(date[i].temperature > max_temp)
                max_temp = date[i].temperature;
       }
    }
    return max_temp;
}

//Высчитываем среднию температуру в месяцаы, проходя по всему массиву структор.
int8_t avr_temp_year(Sensor *date, uint8_t size, Season *m)
{
    int8_t  count = 0;
    int8_t  sum_temp = 0;
    for(int i = 0; i < size; i++){       
       if(date[i].year == m->year){
            sum_temp += date[i].temperature;             
            count++;       
       }
    }
    if (!count)
        return 0;
    return sum_temp/count;
}

int8_t min_temp_year(Sensor *date, uint8_t size, Season *m)
{
    int min_temp = date[0].temperature;
    for(int i = 0; i < size; i++){
       if(date[i].year == m->year){    
            if (date[i].temperature < min_temp)
                min_temp = date[i].temperature;
       }
    }
    return min_temp;
}

int8_t max_temp_year(Sensor *date, uint8_t size, Season *m)
{
    int max_temp = 0;
    for(int i = 0; i < size; i++){
       if(date[i].year == m->year){    
            if (date[i].temperature > max_temp)
                max_temp = date[i].temperature;
       }
    }
    return max_temp;
}


void static_output_fun(Sensor *date, uint8_t size, Season m){
   //int tmp_index = 0;
   if (m.mount == Undefined){
        for(uint8_t i = 1; i <= 13; i++){
            m.mount = i;
            for(int j = 0; j<size; j++){
                if(m.mount == date[j].month && date[j].month != date[j-1].month ){
                    int8_t avr_month = avr_temp_month(date, size, &m);	
                    int8_t min_month = min_temp_month(date, size, &m);
                    int8_t max_month = max_temp_month(date, size, &m);
                    printf("%d %d %d %d %d %d\n", i, date[j].year, date[j].month, avr_month, min_month, max_month);
                }
            }
        }
   }else{
    
   }
}



/*
void static_output_fun(Sensor *date, uint8_t size, Season m){
   int tmp_index = 0;
   if (m.mount == Undefined){
        for(uint8_t i = 1; i <= 12; i++){
                int8_t avr_month = avr_temp_month(date, size, &m);	
                int8_t min_month = min_temp_month(date, size, &m);
                int8_t max_month = max_temp_month(date, size, &m);
                printf("%d %d %d %d %d %d\n", i, date[tmp_index].year, date[tmp_index].month, avr_month, min_month, max_month);
                tmp_index++;
        }
   }
}
*/