#include <stdio.h>
#include "string.h"

int main(void)
{
    string hola = string_create("hola");
    string chau = string_create("chau");
    string kirby = string_create("kirby");

    if (string_eq(hola, kirby))
    {
        printf("'%s' es igual a '%s'\n", string_ref(hola), string_ref(kirby));
    }
    else
    {
        printf("'%s' no es igual a '%s'\n", string_ref(hola), string_ref(kirby));
    }
    if (string_less(hola, chau))
    {
        printf("'%s' es menor que '%s'\n", string_ref(hola), string_ref(chau));
    }
    else
    {
        printf("'%s' es mayor o igual que '%s'\n", string_ref(hola), string_ref(chau));
    }

    hola = string_destroy(hola);
    chau = string_destroy(chau);
    kirby = string_destroy(kirby);
    // aguante kirby por las dudas
    return 0;
}