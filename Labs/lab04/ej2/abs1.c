#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y)
{
    if (x >= 0)
    {
        y = x;
    }
    else
    {
        y = -x;
    }
}

int main(void)
{
    int a = 0, res = 0;
    a = -10;
    absolute(a, res);
    printf("Valor absoluto: %d\n", res);
    return EXIT_SUCCESS;
}

/* Lo que retorna mi programa es:
   Valor absoluto: 0
   No coincide con el resultado del programa en el lenguaje del teorico, ya que en este ultimo res= 10.*/