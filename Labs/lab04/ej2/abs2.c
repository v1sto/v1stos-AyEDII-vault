#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y)
{
    if (x >= 0)
    {
        *y = x;
    }
    else
    {
        *y = -x;
    }
}

int main(void)
{
    int a = 0, res = 0;
    a = -10;
    absolute(a, &res);
    printf("Valor absoluto: %d\n", res);
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

/* c) El parametro int *y es de tipo out.
      C tiene disponibles parametros in y parametros out.*/