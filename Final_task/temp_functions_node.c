#include "temp_functions_node.h"


//Функции для обработки односвязного списка
uint32_t readFileNode(FILE **_fp_in, tNode **pBack, tNode **pHead)
{
    tSensor date;
    uint32_t count = 0;
    int r;
    int Y, M, D, h, m, t;
    while (1)
    {
        r = fscanf(*_fp_in, "%d;%d;%d;%d;%d;%d", &Y, &M, &D, &h, &m, &t);
        static int line = 1;
        if (r == EOF)
            return count;
        if (r < 6)
        {
            char s[20];
            fgets(s, sizeof(s), *_fp_in);
            printf("Error in line %d\n", line);
        }
        else
        {
            addRecordNode(&date, Y, M, D, h, m, t);
            if (!*pHead)
            {
                *pHead = addListFront(*pHead, date);
                *pBack = *pHead;
            }
            else
                *pBack = addListBack(*pBack, date);
            count++;
        }
        line++;
    }
}

void addRecordNode(tSensor *pDate, uint16_t year, uint8_t mount, uint8_t day, uint8_t hour,
                   uint8_t min, int16_t temperature)
{
    pDate->year = year;
    pDate->month = mount;
    pDate->day = day;
    pDate->hour = hour;
    pDate->min = min;
    pDate->temperature = temperature;
}

tNode *addListFront(tNode *pHead, tSensor data)
{
    tNode *pNode = malloc(sizeof(tNode));
    pNode->data = data;
    pNode->next = pHead;
    return pNode;
}

tNode *addListBack(tNode *pBack, tSensor data)
{

    tNode *pNode;
    pNode = malloc(sizeof(tNode));
    pNode->data = data;
    pNode->next = NULL;
    pBack->next = pNode;
    return pNode;
}

tNode *delList(tNode *pHead)
{
    while (pHead)
        pHead = delNode(pHead);
    return pHead;
}

tNode *delNode(tNode *pTop)
{
    if (pTop == NULL)
        return pTop;
    tNode *pNode = pTop->next;
    free(pTop);
    return pNode;
}

void printList(tNode *pTop)
{
    if (!pTop)
        printf("is Node Null\n");
    for (tNode *pNode = pTop; pNode != NULL; pNode = pNode->next)
        printf("%04d-%02d-%02d %02d:%02d temp = %d\n",
               pNode->data.year,
               pNode->data.month,
               pNode->data.day,
               pNode->data.hour,
               pNode->data.min,
               pNode->data.temperature);
}

void static_output_node(tNode *pHead, tSeason *pSeason)
{
    int year = pHead->data.year;
    int month = pHead->data.month;
    int min_temp = pHead->data.temperature;
    int max_temp = pHead->data.temperature;
    int counn_avr  = 0;
    float avr_month = 0;
    float sum_count = 0;
    tNode *pNode = pHead;
    while (1)
    {
        //if (pSeason->month == Undefined)
            
            if (month == pNode->data.month)
            {
                min_temp = pNode->data.temperature > min_temp ? min_temp : pNode->data.temperature;
                max_temp = pNode->data.temperature < max_temp ? max_temp : pNode->data.temperature;
                sum_count += pNode->data.temperature;
                counn_avr++; 
            }
            else
            {
                avr_month = sum_count/counn_avr;
                if (pSeason->month == Undefined)
                    printf("%d %6d %6.2f %8d %8d\n", year, month, avr_month, min_temp, max_temp);        
                else 
                    if (pSeason->month == month){
                        printf("%d %6d %6.2f %8d %8d\n", year, pSeason->month, avr_month, min_temp, max_temp);
                        return;
                    }
                min_temp = pNode->data.temperature;
                max_temp = pNode->data.temperature;
                month = pNode->data.month;
                year = pNode->data.year;
                sum_count = 0;
                counn_avr  = 0;
                avr_month = 0;
            }
            pNode = pNode->next;            
            if (!pNode)
            {
                avr_month = sum_count/counn_avr;
                printf("%d %6d %6.2f %8d %8d\n", year, month, avr_month, min_temp, max_temp);
                return;
            }
    }
}

int16_t max_temp_year_node(tNode *pHead, uint32_t size, tSeason *pSeason)
{
    int max_temp = TEMP_MIN;
    for (tNode *pNode = pHead; pNode != NULL; pNode = pNode->next)
    {
        if (pNode->data.year == pSeason->year)
        {
            if (pNode->data.temperature > max_temp)
                max_temp = pNode->data.temperature;
        }
    }
    return max_temp;
}

int16_t min_temp_year_node(tNode *pHead, uint32_t size, tSeason *pSeason)
{
    int min_temp = TEMP_MAX;
    for (tNode *pNode = pHead; pNode != NULL; pNode = pNode->next)
    {
        if (pNode->data.year == pSeason->year)
        {
            if (pNode->data.temperature < min_temp)
                min_temp = pNode->data.temperature;
        }
    }
    return min_temp;
}

float avr_temp_year_node(tNode *pHead, uint32_t size, tSeason *pSeason)
{
    uint32_t count = 0;
    float sum_temp = 0.0;
    for (tNode *pNode = pHead; pNode != NULL; pNode = pNode->next)
    {
        if (pNode->data.year == pSeason->year)
        {
            sum_temp += pNode->data.temperature;
            count++;
        }
    }
    if (!count)
        return 0;
    return sum_temp / count;
}

