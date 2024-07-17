#include <stdlib.h>
#include <stdio.h>

void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

int main(void)
{
    int a = 6, b = 4;
    printf("Valores originales:  x = %d , y = %d\n", a, b);
    swap(&a, &b);
    printf("Valores cambiados:  x = %d , y = %d\n", a, b);
    return EXIT_SUCCESS;
}
