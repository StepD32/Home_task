#include "temp_api.c"

int main(int argc, char **argv)
{
	tNode *pBack = NULL;
	tNode *pHead = NULL;
	tSeason month = {2021, Undefined};

	FILE *fp;
	char name_file[] = "temperature_big.csv";

//Открываем файл, если при открытии ошибка выходим из программы
	if (openFile(&fp, name_file))
	{
		printf("Exit program.\n");
		return 0;
	}

//Читаем файл и создаем односвязный список для хранения неизвестного количества записей
//В список добавлем значения в конц. Первым пришёл — первым ушёл.
	uint32_t count_date = readFileNode(&fp, &pBack, &pHead);
	
	//Закрваем файл после считывания 
	fclose(fp);

	printf("Processed values = %d\n", count_date);
	printf("Year Month MonthAvr MonthMin MonthMax\n");


//Последовательно проходимся по списку, выводим данные по каждому месяцу.
//В функцию передаем начала списка и фильтр за какой месяй обробатывем данные.
	static_output_node(pHead, &month);

//Обрабатываем данный за указанный год.
	float avr_year = avr_temp_year_node(pHead, count_date, &month);
	int16_t min_year = min_temp_year_node(pHead, count_date, &month);
	int16_t max_year = max_temp_year_node(pHead, count_date, &month);
	printf("Year statistic: average %0.5f, min %d,  max %d\n", avr_year, min_year, max_year);

//Освобождаем память в куче.
	pHead = delList(pHead);

	/*
		printf("# Year Month MonthAvr MonthMin MonthMax\n");
		static_output(sensor, count_date, &st_month);
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