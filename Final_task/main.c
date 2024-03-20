#include "temp_functions.h"

int main(int argc, char **argv)
{
	tNode *pBack = NULL;
	tNode *pHead = NULL;
	tSeason Month = {2021, Undefined};
	char *name_file = {0};
	uint8_t m = 0;
	FILE *fp;

	int rez = 0;
	if (argc == 1)
	{
		puts("Temp statistic application. Please \"-h\" enter key:");
		puts("-h for help");
		return 0;
	}
	while ((rez = getopt(argc, argv, "hf:m:")) != -1)
	{
		switch (rez)
		{
		case 'h':
			puts("Temp statistic application. Please enter key:");
			puts("-h for help");
			puts("-f file_name for load this file");
			puts("-m xx statistic for xx month");
			return 0;
		case 'f':
			name_file = optarg;
			break;
		case 'm':
			m = atoi(optarg);
			break;
		case '?':
			puts("Temp statistic application. Please enter key:");
			puts("-h for help");
			puts("-f file_name for load this file");
			puts("-m xx statistic for xx month");
			return 0;
			break;
		default:
			printf("Error found defaul !\n");
			return 0;
		};
	};

	Month.month = m;
	
	// Открываем файл, если при открытии ошибка выходим из программы
	if (openFile(&fp, name_file))
	{
		printf("Exit program.\n");
		return 0;
	}

	// Читаем файл и создаем односвязный список для хранения неизвестного количества записей
	// Добавлем значения в конец списка. Первым пришёл — первым ушёл.
	uint32_t count_date = readFileNode(&fp, &pBack, &pHead);

	// Закрываем файл после считывания
	fclose(fp);

	printf("Processed values = %d\n", count_date);
	printf("Year  Month MonthAvr MonthMin MonthMax\n");

	// Последовательно проходимся по списку, выводим данные по каждому месяцу.
	// В функцию передаем начала списка и фильтр за какой месяц обробатывем данные.
	static_output_node(pHead, &Month);

	// Обрабатываем данные за указанный год.
	float avr_year = avr_temp_year_node(pHead, count_date, &Month);
	int16_t min_year = min_temp_year_node(pHead, count_date, &Month);
	int16_t max_year = max_temp_year_node(pHead, count_date, &Month);
	if (Month.month == Undefined)
		printf("Year statistic: average %0.5f, min %d,  max %d\n", avr_year, min_year, max_year);

	// Освобождаем память в куче.
	pHead = delList(pHead);

	return 0;
}