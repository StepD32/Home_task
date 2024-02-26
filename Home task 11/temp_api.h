#ifndef TEMP_API
#define TEMP_API

#include <stdint.h>
#include <stdio.h>
#include <string.h>


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

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;  
    uint8_t hour;
    uint8_t min;
    int8_t temperature;
} SENSOR;

typedef enum{
    yan = 8

} MONTH;

uint8_t addRecord(SENSOR *date, uint8_t index,
                uint16_t year, 
                uint8_t mount, 
                uint8_t day, 
                uint8_t hour, 
                uint8_t min, 
                int8_t temperature            
            );


int AddInfo(SENSOR* info, int num);

void print(SENSOR* date, int num);

int8_t avr_temp_month(SENSOR *date, uint8_t size, MONTH month);
int8_t min_temp_month(SENSOR *date, uint8_t size, MONTH month);
int max_temp_month(SENSOR *date, uint8_t size, MONTH month);

int8_t avr_temp_year(SENSOR *date, uint8_t size, uint8_t year);
int8_t min_temp_year(SENSOR *date, uint8_t size, uint8_t year);
int8_t max_temp_year(SENSOR *date, uint8_t size, uint8_t year);

#endif
