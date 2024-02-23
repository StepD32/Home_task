#include "temp_api.h"

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
uint8_t addRecord (struct sensor *_date, uint8_t _index, uint16_t _year, uint8_t _mount, uint8_t _day, uint8_t _hour, 
                uint8_t _min, int8_t _temperature)
{
    _date[_index].year = _year;
    _date[_index].month = _year;
    _date[_index].day = _day;
    _date[_index].hour = _hour;
    _date[_index].min = _min;
    _date[_index].temperature = _temperature;    
    return _index;
}

//Функция печати данный из массива структор по индексу 
void print(struct sensor *_date, int _index) 
{
    printf("%d %04d-%02d-%02d %02d:%02d t=%3d\n",
            _index,
            _date[_index].year,
            _date[_index].month,
            _date[_index].day,
            _date[_index].hour,
            _date[_index].min,
            _date[_index].temperature
    );
}


//Высчитываем среднию температуру в месяце, проходя по всему массиву структор.
int8_t avr_temp_month(struct sensor *_date, uint8_t _size, uint8_t _month)
{
    int count = 0;
    int sum_temp = 0;
    for(int i = 0; i < _size; i++)
    {
       it (_date[i].month == _month)
       {
            sum_temp += _date[i].temperature;
            count++;       
       }
    }

    return sum_temp/count;

}

//Высчитываем минимальную температуру в месяце, проходя по всему массиву структор.
int8_t min_temp_month(struct sensor *_date, uint8_t _size, uint8_t _month)
{
    int count = 0;
    int min_temp = _date[0].temperature;
    for(int i = 0; i < _size; i++)
    {
       if(_date[i].month == _month)
       {    
            _date[i].temperature < min_temp;
            min_temp = _date[i].temperature;
       }
    }

    return min_temp;
}

//Высчитываем максимальную температуру в месяце, проходя по всему массиву структор.
int8_t max_temp_month(struct sensor *_date, uint8_t _size, uint8_t _month)
{
    int count = 0;
    int max_temp = _date[0].temperature;
    for(int i = 0; i < _size; i++)
    {
       if(_date[i].month == _month)
       {    
            _date[i].temperature > max_temp;
            max_temp = _date[i].temperature;
       }
    }

    return max_temp;
}