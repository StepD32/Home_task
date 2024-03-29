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

// Функция добавления новых данных о температуре в массив структур по индексу.

#include "temp_functions.h"

void addRecord(tSensor *pDate, uint32_t index, uint16_t year, uint8_t mount, uint8_t day, uint8_t hour,
               uint8_t min, int16_t temperature)
{
    pDate[index].year = year;
    pDate[index].month = mount;
    pDate[index].day = day;
    pDate[index].hour = hour;
    pDate[index].min = min;
    pDate[index].temperature = temperature;
}

int DelSensor(tSensor *pDate, uint16_t index, int struc_size)
{
    int count = struc_size - index;
    for (int i = index; i <= count; i++)
    {
        pDate[i] = pDate[i + 1];
    }
    return --struc_size;
}
// Функция печати данных из массива структур по индексу
void print(tSensor *pDate, uint16_t size_struct)
{
    for (int16_t i = 0; i < size_struct; i++)
        printf("%d %04d-%02d-%02d %02d:%02d temp = %d\n",
               i,
               pDate[i].year,
               pDate[i].month,
               pDate[i].day,
               pDate[i].hour,
               pDate[i].min,
               pDate[i].temperature);
}

// Высчитываем среднюю температуру в месяц, проходит по всему массиву структур.
float avr_temp_month(tSensor *pDate, uint32_t size, tSeason *pSeason)
{
    uint32_t count = 0;
    float sum_temp = 0.0;
    for (uint32_t i = 0; i < size; i++)
    {
        if (pDate[i].month == pSeason->month)
        {
            int temp = pDate[i].temperature;
            sum_temp += temp;
            count++;
        }
    }
    if (!count)
        return 0;
    return sum_temp / count;
}

// Высчитываем минимальную температуру месяца, проходя по всему массиву структур.
int16_t min_temp_month(tSensor *pDate, uint32_t size, tSeason *pSeason)
{
    int min_temp = 99;
    for (uint32_t i = 0; i < size; i++)
    {
        if (pDate[i].month == pSeason->month)
        {
            if (pDate[i].temperature < min_temp)
                min_temp = pDate[i].temperature;
        }
    }
    return min_temp;
}

// Высчитываем максимальную температуру месяца, проходя по всему массиву структур.
int16_t max_temp_month(tSensor *pDate, uint32_t size, tSeason *pSeason)
{
    int8_t max_temp = -99;
    for (uint32_t i = 0; i < size; i++)
    {
        if (pDate[i].month == pSeason->month)
        {
            if (pDate[i].temperature > max_temp)
                max_temp = pDate[i].temperature;
        }
    }
    return max_temp;
}

// Высчитываем среднюю температуру в год, проходя по всему массиву структур.
float avr_temp_year(tSensor *pDate, uint32_t size, tSeason *pSeason)
{
    uint32_t count = 0;
    float sum_temp = 0.0;
    for (int i = 0; i < size; i++)
    {
        if (pDate[i].year == pSeason->year)
        {
            sum_temp += pDate[i].temperature;
            count++;
        }
    }
    if (!count)
        return 0;
    return sum_temp / count;
}

int16_t min_temp_year(tSensor *pDate, uint32_t size, tSeason *pSeason)
{
    int min_temp = pDate[0].temperature;
    for (int i = 0; i < size; i++)
    {
        if (pDate[i].year == pSeason->year)
        {
            if (pDate[i].temperature < min_temp)
                min_temp = pDate[i].temperature;
        }
    }
    return min_temp;
}

int16_t max_temp_year(tSensor *pDate, uint32_t size, tSeason *pSeason)
{
    int max_temp = 0;
    for (int i = 0; i < size; i++)
    {
        if (pDate[i].year == pSeason->year)
        {
            if (pDate[i].temperature > max_temp)
                max_temp = pDate[i].temperature;
        }
    }
    return max_temp;
}

void static_output(tSensor *pDate, uint32_t size, tSeason *pSeason)
{
    // int tmp_index = 0;
    if (pSeason->month == Undefined)
    {
        for (uint8_t i = 1; i <= 13; i++)
        {
            pSeason->month = i;
            for (uint32_t j = 0; j < size; j++)
            {
                if (pSeason->month == pDate[j].month && pDate[j].month != pDate[j - 1].month)
                {
                    float avr_month = avr_temp_month(pDate, size, pSeason);
                    int16_t min_month = min_temp_month(pDate, size, pSeason);
                    int16_t max_month = max_temp_month(pDate, size, pSeason);
                    printf("%d %2d %3d %6.2f %8d %8d\n", i, pDate[j].year, pDate[j].month, avr_month, min_month, max_month);
                }
            }
        }
    }
}

void swap(tSensor *pDate, uint32_t num_one, uint32_t num_two)
{
    tSensor temp;
    temp = pDate[num_one];
    pDate[num_one] = pDate[num_two];
    pDate[num_two] = temp;
}

void sortByDate(tSensor *pDate, uint16_t num_one, uint16_t size)
{
    for (int i = 0; i < size; ++i)
        for (int j = i; j < size; ++j)
            if (dateToInt(pDate + i) >= dateToInt(pDate + j))
                swap(pDate, i, j);
}

uint32_t dateToInt(tSensor *pDate)
{
    return pDate->year << 16 | pDate->month << 8 | pDate->day;
}

int openFile(FILE **_fp_in, const char *_input_fn)
{
    if ((*_fp_in = fopen(_input_fn, "r")) == NULL)
    {
        perror("Error occured while opening input file");
        return 1;
    }
    return 0;
}

uint32_t readFile(FILE **_fp_in, tSensor *pDate)
{
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
            printf("Error in line %d value %s\n", line, s);
        }
        else
            addRecord(pDate, count++, Y, M, D, h, m, t);
        line++;
    }
}

