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

struct sensor 
{
    uint16_t year;
    uint8_t month;
    uint8_t day;  
    uint8_t hour;
    uint8_t min;
    int8_t temperature;
} ;

struct sensor arrayDataSensor[SIZE];



struct tempStat
{
    uint16_t year;
    uint8_t month;
    int8_t avrTemp;
    int8_t minTemp;
    int8_t maxTemp;
};

uint8_t addRecord(struct sensor *_date, uint8_t _index,
                uint16_t _year, 
                uint8_t _mount, 
                uint8_t _day, 
                uint8_t _hour, 
                uint8_t min, 
                int8_t _temperature            
            );


void print(struct sensor* _date, int _num);

int8_t avr_temp_month(struct sensor *_date, uint8_t _size, uint8_t _month);
int8_t min_temp_month(struct sensor *_date, uint8_t _size, uint8_t _month);
int8_t max_temp_month(struct sensor *_date, uint8_t _size, uint8_t _month);

int8_t avr_temp_year(struct sensor *_date, uint8_t _size, uint8_t _year);
int8_t min_temp_year(struct sensor *_date, uint8_t _size, uint8_t _year);
int8_t max_temp_year(struct sensor *_date, uint8_t _size, uint8_t _year);

#endif
