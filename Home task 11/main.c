#include "temp_api.h"

#define SIZE_SENSOR 4

int main(int argc, char **argv)
{
	Sensor Senser[SIZE_SENSOR];
	Season st_month = {2021, August};

	AddInfo(Senser);

	for(int i = 0; i<SIZE_SENSOR; i++)
		print(Senser,i);

	int8_t avr_month  = avr_temp_month(Senser, SIZE_SENSOR, &st_month);	
	printf("temperature month avr = %d\n", avr_month);	

	int8_t min_month = min_temp_month(Senser, SIZE_SENSOR, &st_month);
	printf("temperature month min = %d\n", min_month);

	int8_t max_month = max_temp_month(Senser, SIZE_SENSOR, &st_month);
	printf("temperature month max = %d\n", max_month);
		
	int8_t avr_year = avr_temp_year(Senser, SIZE_SENSOR, &st_month);
	printf("temperature year avr  = %d\n", avr_year);
	
	int8_t min_year = min_temp_year(Senser, SIZE_SENSOR, &st_month);
	printf("temperature year min  = %d\n", min_year);

	int8_t max_year = max_temp_year(Senser, SIZE_SENSOR, &st_month);
	printf("temperature year max  = %d\n", max_year);

	return 0;
}

