#include "temp_api.c"

#define SIZE_SENSOR 60000000

int main(int argc, char **argv)
{
	//Sensor* sensor = malloc(SIZE_SENSOR*sizeof(Sensor));
	//if(!sensor)
	//	return -1;


	tNode *pBack = NULL;
	tNode *pHead = NULL;
	tSeason st_month = {2021, Undefined};

	FILE *fp;
	char name_file[] = "temperature_big.csv";

	if (openFile(&fp, name_file)){
		printf("Exit program.\n");
		return 0;
	}	

	uint32_t count_date  = readFileNode(&fp, &pBack, &pHead);
	fclose(fp);

	printf("Processed values = %d\n", count_date);
	printList(pHead);

/*
	printf("# Year Month MonthAvr MonthMin MonthMax\n");
	static_output_fun(sensor, count_date, &st_month);
	float avr_year = avr_temp_year(sensor, count_date, &st_month);
	int16_t min_year = min_temp_year(sensor, count_date, &st_month);
	int16_t max_year = max_temp_year(sensor, count_date, &st_month);
	printf("Year statistic: average %0.5f, min %d,  max %dB\n", avr_year, min_year, max_year);

	free(sensor);

	printf("\nPrint these structures\n");
	print(sensor, size_strc_sensor);

	printf("\nSwap num %d and num %d structures\n", 0, 1);
	swap(sensor, 0, 1);
	print(sensor, size_strc_sensor);

	printf("\nDelete num %d\n", 0);
	size_strc_sensor = DelSensor(sensor, 0, size_strc_sensor);
	print(sensor, size_strc_sensor);

*/
	return 0;
}