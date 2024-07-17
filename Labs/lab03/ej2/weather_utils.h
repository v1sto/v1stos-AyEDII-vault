#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

int min_temp(WeatherTable a);

void procedimiento(WeatherTable a, int output[YEARS]);

void mes_max_pre(WeatherTable a, month_t output[YEARS]);

#endif