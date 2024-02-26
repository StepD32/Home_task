/*
 * main.c
 * 
 * Copyright 2024 Mitya <Mitya@SER5>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "temp_api.h"

#define SIZE_SENSOR 4

int main(int argc, char **argv)
{
	SENSOR Senser[SIZE_SENSOR];
	MONTH month  = yan;
	int num = 0;
  AddInfo(Senser, num);

	int8_t temp  = avr_temp_month(Senser, SIZE_SENSOR, month);	
	printf("temperature avr = %d\n", temp);	

	int8_t min = min_temp_month(Senser, SIZE_SENSOR, month);
	printf("temperature min = %d\n", min);

	int8_t max = max_temp_month(Senser, SIZE_SENSOR, month);
	printf("temperature max = %d\n", max);

	return 0;
}

