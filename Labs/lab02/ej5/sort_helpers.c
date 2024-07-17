#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "fixstring.h"

void swap(fixstring a[], unsigned int i, unsigned int j)
{
    fixstring aux;
    fstring_set(aux, a[i]);
    fstring_set(a[i], a[j]);
    fstring_set(a[j], aux);
}

bool goes_before(fixstring x, fixstring y)
{
    bool aux = false;
    unsigned int i = 0;
    while (x[i] == y[i] && x[i] != '\0' && y[i] != '\0')
    {
        i++;
    }
    if (x[i] == '\0')
    {
        aux = true;
    }
    if (y[i] != '\0')
    {
        aux = false;
    }
    aux = x[i] < y[i];
    return aux;
}

bool array_is_sorted(fixstring array[], unsigned int length)
{
    unsigned int i = 1;
    while (i < length && goes_before(array[i - 1], array[i]))
    {
        i++;
    }
    return (i >= length);
}