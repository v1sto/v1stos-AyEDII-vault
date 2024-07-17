#include "array_helpers.h"
#include <stdio.h>
#include "mybool.h"

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath)
{
    unsigned int array_size;
    FILE *f = fopen(filepath, "r");
    fscanf(f, "%u", &array_size);

    if (array_size > max_size)
    {
        array_size = max_size;
    }

    for (unsigned int i = 0; i < array_size; i++)
    {
        fscanf(f, "%d", &array[i]);
    }

    return array_size;
}

void array_dump(int a[], unsigned int length)
{
    printf("[");
    for (unsigned int i = 0; i < length; i++)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%d", a[i]);
    }
    printf("]\n");
}

bool array_is_sorted(int a[], unsigned int length)
{
    bool x = true;
    for (unsigned int i = 0; i < length - 1; i++)
    {
        if (a[i] >= a[i + 1])
        {
            x = false;
        }
    }
    return x;
}