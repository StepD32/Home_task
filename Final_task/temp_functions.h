#ifndef TEMP_API
#define TEMP_API

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 30
#define TEMP_MAX 99
#define TEMP_MIN -99
/*
Структура типа:
    - dddd - год 4
    - цифры mm - месяц 2 символа
    - dd - день 2 цифры
    - hh - часы 2 цифры
    - mm - минуты 2 цифры
    - temperature - целое число от -99 до 99
*/

typedef enum
{
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

} tMonth;

typedef struct
{
    uint16_t year;
    uint8_t month : 4;
    uint8_t day : 5;
    uint8_t hour : 5;
    uint8_t min : 6;
    int8_t temperature;
} tSensor;

typedef struct node
{
    tSensor data;
    struct node *next;
} tNode;

typedef struct
{
    uint16_t year;
    tMonth month;
} tSeason;

void addRecord(tSensor *pDate, uint32_t index,
               uint16_t year,
               uint8_t mount,
               uint8_t day,
               uint8_t hour,
               uint8_t min,
               int16_t temperature);

int DelSensor(tSensor *pDate, uint16_t index, int struc_size);

void print(tSensor *pDate, uint16_t num);

float avr_temp_month(tSensor *pDate, uint32_t size, tSeason *pSeason);
int16_t min_temp_month(tSensor *pDate, uint32_t size, tSeason *pSeason);
int16_t max_temp_month(tSensor *pDate, uint32_t size, tSeason *pSeason);

float avr_temp_year(tSensor *pDate, uint32_t size, tSeason *pSeason);
int16_t min_temp_year(tSensor *pDate, uint32_t size, tSeason *pSeason);
int16_t max_temp_year(tSensor *pDate, uint32_t size, tSeason *pSeason);

void static_output(tSensor *pDate, uint32_t size, tSeason *pSeason);
void swap(tSensor *pDate, uint32_t num_one, uint32_t num_two);
void sortByDate(tSensor *pDate, uint16_t num_one, uint16_t size);
uint32_t dateToInt(tSensor *pDate);
int openFile(FILE **_fp_in, const char *_input_fn);
uint32_t readFile(FILE **_fp_in, tSensor *date);

#endif
