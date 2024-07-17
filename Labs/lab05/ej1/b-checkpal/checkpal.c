#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 50

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main()
{
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.'};
    char *filtered = NULL;
    char *aux = NULL;
    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: ", MAX_LENGTH);

    char *input = fgets(user_input, MAX_LENGTH, stdin);

    input[string_length(input) - 1] = '\0';

    filtered = string_filter(input, ignore_chars[0]);
    aux = filtered;
    for (unsigned int i = 0; i < SIZEOF_ARRAY(ignore_chars); i++)
    {
        filtered = string_filter(filtered, ignore_chars[i]);
        free(aux);
        aux = filtered;
    }

    printf("El texto:\n\n"
           "\"%s\" \n\n"
           "%s un palíndromo.\n\n",
           input, string_is_symmetric(filtered) ? "Es" : "NO es");
    free(aux);
    return EXIT_SUCCESS;
}
