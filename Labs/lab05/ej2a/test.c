#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

int main(void)
{
    // ¿Funciona bien stack_pop() para pilas de tamaño 1?
    stack s = stack_empty();
    s = stack_push(s, 1);
    printf("Stack size: %d \n", stack_size(s));
    printf("Stack top: %d \n", stack_top(s));
    s = stack_pop(s);
    if (stack_is_empty(s))
    {
        printf("Stack is now empty.\n");
    }
    // Si la pila queda vacía, ¿puedo volver a insertar elementos?
    s = stack_push(s, 2);
    printf("Stack size: %d \n", stack_size(s));
    printf("Stack top: %d \n", stack_top(s));
    s = stack_pop(s);
    // ¿La función stack_to_array() devuelve NULL para una pila vacía? ¿Devuelve los elementos en el orden correcto?

    stack_elem *array = stack_to_array(s);
    if (array == NULL)
    {
        printf("Empty.\n");
    }
    else
    {
        printf("Error. Test failed.\n");
    }
    s = stack_destroy(s);
    free(array);
    return EXIT_SUCCESS;
}

/*Stack size: 1
Stack top: 1
Stack is now empty.
Stack size: 1
Stack top: 2
Empty.*/