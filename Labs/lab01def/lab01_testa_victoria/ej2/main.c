#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

unsigned int array_from_stdin(int array[], unsigned int max_size)
{
    unsigned int total;
    scanf("%u", &total);

    if (total > max_size)
    {
        total = max_size;
    }

    for (unsigned int i = 0; i < total; i++)
    {
        scanf("%d", &array[i]);
    }

    return total;
}

void array_dump(int a[], unsigned int length)
{
    printf("[");
    for (unsigned int i = 0; i < length; i++)
    {
        if (i != 0)
        {
            printf(" ,");
        }
        printf("%d", a[i]);
    }
    printf("]\n");
}

int main()
{
    int array[MAX_SIZE];
    unsigned int length = array_from_stdin(array, MAX_SIZE);
    array_dump(array, length);

    return EXIT_SUCCESS;
}
