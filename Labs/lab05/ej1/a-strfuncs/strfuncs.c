#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "strfuncs.h"

size_t string_length(const char *str)
{
    size_t i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

char *string_filter(const char *str, char c)
{
    size_t length = string_length(str);
    size_t i = 0;
    for (size_t k = 0; k < length; k++)
    {
        if (str[k] != c)
        {
            i++;
        }
    }
    char *strdef = malloc(sizeof(char) * (i + 1));
    size_t j = 0;
    for (size_t l = 0; l < length; l++)
    {
        if (str[l] != c)
        {
            strdef[j++] = str[l];
        }
    }
    strdef[i] = '\0';
    return strdef;
}

bool string_is_symmetric(const char *str)
{
    size_t length = string_length(str);
    unsigned int i = 0u;
    bool res = true;
    while (i < length / 2)
    {
        res = res && (str[i] == str[length - 1 - i]);
        i++;
    }
    return res;
}