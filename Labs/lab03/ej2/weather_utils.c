#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

int min_temp(WeatherTable a)
{
    int min = a[0][0][0]._min_temp;
    for (unsigned int i = 0; i < YEARS; i++)
    {
        for (unsigned int j = 0; j < MONTHS; j++)
        {
            for (unsigned int k = 0; k < DAYS; k++)
            {
                if (a[i][j][k]._min_temp < min)
                {
                    min = a[i][j][k]._min_temp;
                }
            }
        }
    }
    return min;
}

void procedimiento(WeatherTable a, int output[YEARS])
{
    for (unsigned int year = 0; year < YEARS; year++)
    {
        int max = a[year][0][0]._max_temp;
        for (unsigned int i = 0; i < MONTHS; i++)
        {
            for (unsigned int j = 0; j < DAYS; j++)
            {
                if (a[year][i][j]._max_temp > max)
                {
                    max = a[year][i][j]._max_temp;
                }
            }
        }
        output[year] = max;
    }
}

void mes_max_pre(WeatherTable a, month_t output[YEARS])
{
    for (unsigned int year = 0; year < YEARS; year++)
    {
        unsigned int max = a[year][0][0]._rainfall;
        month_t mes = january;
        for (unsigned int i = 0; i < MONTHS; i++)
        {
            for (unsigned int j = 0; j < DAYS; j++)
            {
                if (a[year][i][j]._rainfall > max)
                {
                    max = a[year][i][j]._rainfall;
                    mes = i;
                }
            }
        }
        output[year] = mes;
    }
}
