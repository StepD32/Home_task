#ifndef TEMP_API_NODE
#define TEMP_API_NODE


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_functions.h"


typedef struct node
{
    tSensor data;
    struct node *next;
} tNode;


// Функции для работы односвязного списка
uint32_t readFileNode(FILE **_fp_in, tNode **pBack, tNode **pHead);
void addRecordNode(tSensor *date, uint16_t year, uint8_t mount, uint8_t day, uint8_t hour, uint8_t min, int16_t temperature);
tNode *addListFront(tNode *pTop, tSensor data);
tNode *addListBack(tNode *pBack, tSensor data);
tNode *delList(tNode *pTop);
tNode *delNode(tNode *pTop);
void printList(tNode *pTop);

void static_output_node(tNode *pHead, tSeason *pSeason);
int16_t min_temp_year_node(tNode *pHead, uint32_t size, tSeason *pSeason);
int16_t max_temp_year_node(tNode *pHead, uint32_t size, tSeason *pSeason);
float avr_temp_year_node(tNode *pHead, uint32_t size, tSeason *pSeason);



#endif