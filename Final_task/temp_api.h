#ifndef TEMP_API
#define TEMP_API

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SIZE 30

/*
Структура типа:
    - dddd - год 4
    - цифры mm - месяц 2 символа
    - dd - день 2 цифры
    - hh - часы 2 цифры
    - mm - минуты 2 цифры
    - temperature - целое число от -99 до 99
*/

typedef enum {
    Undefined = 0,
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December

} Month;

typedef struct {
    uint16_t year;
    uint8_t month       :4;
    uint8_t day         :5;  
    uint8_t hour        :5;
    uint8_t min         :6;
    int8_t temperature;
    int16_t count;
} Sensor;

typedef struct{
    uint16_t year;
    Month mount;
} Season;

void addRecord(Sensor *date, uint32_t index,
                uint16_t year, 
                uint8_t mount, 
                uint8_t day, 
                uint8_t hour, 
                uint8_t min, 
                int16_t temperature            
            );

int DelSensor(Sensor *date, uint16_t index,  int struc_size);

void print(Sensor *date, uint16_t num);

float avr_temp_month(Sensor *date, uint32_t size, Season *m);
int16_t min_temp_month(Sensor *date, uint32_t size, Season *m);
int16_t max_temp_month(Sensor *date, uint32_t size, Season *m);

int16_t avr_temp_year(Sensor *date, uint32_t size, Season *m);
int16_t min_temp_year(Sensor *date, uint32_t size, Season *m);
int16_t max_temp_year(Sensor *date, uint32_t size, Season *m);

void static_output_fun(Sensor *date, uint32_t size, Season *m);

void swap(Sensor *date, uint32_t num_one, uint32_t num_two);

void sortByDate(Sensor *date, uint16_t num_one, uint16_t size);
uint32_t dateToInt(Sensor *date);

int openFile(FILE **_fp_in, const char *_input_fn);
uint32_t readFile(FILE **_fp_in, Sensor *date);
#endif
