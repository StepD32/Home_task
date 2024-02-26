#include "temp_api.c"

#define SIZE_SENSOR 360

int main(int argc, char **argv)
{
	Sensor sensor[SIZE_SENSOR];
	Season st_month = {2021, Undefined};	
	int size_strc_sensor = AddInfo(sensor);

	printf("# Year Month MonthAvr MonthMax MonthMin\n");
	static_output_fun(sensor, size_strc_sensor, &st_month);
	int8_t avr_year = avr_temp_year(sensor, size_strc_sensor, &st_month);
	int8_t min_year = min_temp_year(sensor, size_strc_sensor, &st_month);
	int8_t max_year = max_temp_year(sensor, size_strc_sensor, &st_month);
	printf("Year statistic: average %d, max %d, min %d\n",avr_year, max_year, min_year);

	return 0;
}

