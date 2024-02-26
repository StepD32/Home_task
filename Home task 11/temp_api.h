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

typedef enum {
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
} Sensor;

typedef struct{
    uint16_t year;
    Month mount;
} Season;


uint8_t addRecord(Sensor *date, uint8_t index,
                uint16_t year, 
                uint8_t mount, 
                uint8_t day, 
                uint8_t hour, 
                uint8_t min, 
                int8_t temperature            
            );


int AddInfo(Sensor* info);

void print(Sensor* date, int num);

int8_t avr_temp_month(Sensor *date, uint8_t size, Season *m);
int8_t min_temp_month(Sensor *date, uint8_t size, Season *m);
int max_temp_month(Sensor *date, uint8_t size, Season *m);

int8_t avr_temp_year(Sensor *date, uint8_t size, Season *m);
int8_t min_temp_year(Sensor *date, uint8_t size, Season *m);
int8_t max_temp_year(Sensor *date, uint8_t size, Season *m);

#endif
