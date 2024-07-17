#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack
{
    stack_elem *elems;     // Arreglo de elementos
    unsigned int size;     // Cantidad de elementos en la pila
    unsigned int capacity; // Capacidad actual del arreglo elems
};

bool invrep(stack s)
{
    return s->size <= s->capacity;
}

stack stack_empty()
{
    stack s = NULL;
    s = malloc(sizeof(struct _s_stack));
    s->size = 0u;
    s->capacity = 0u;
    s->elems = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e)
{
    assert(invrep(s));
    if (s->size == s->capacity)
    {
        if (stack_is_empty(s))
        {
            s->capacity = 10;
            s->elems = calloc(s->capacity, sizeof(stack_elem));
            s->elems[s->size] = e;
            s->size++;
        }
        else
        {
            s->elems = realloc(s->elems, s->capacity * 2);
            s->elems[s->size] = e;
            s->size++;
            ;
        }
    }
    else if (s->size < s->capacity)
    {
        s->elems[s->size] = e;
        s->size++;
    }
    assert(invrep(s));

    return s;
}

stack stack_pop(stack s)
{
    assert(invrep(s));
    assert(!stack_is_empty(s));
    s->size--;
    assert(invrep(s));
    return s;
}

unsigned int stack_size(stack s)
{
    return s->size;
}

stack_elem stack_top(stack s)
{
    assert(invrep(s));
    assert(!stack_is_empty(s));
    return s->elems[s->size - 1];
}

bool stack_is_empty(stack s)
{
    assert(invrep(s));
    return (s->size == 0);
}

stack_elem *stack_to_array(stack s)
{
    assert(invrep(s));
    if (stack_is_empty(s))
    {
        return NULL;
    }
    stack_elem *array = calloc(s->size, sizeof(stack_elem));
    for (unsigned int i = 0u; i < s->size; i++)
    {
        array[i] = s->elems[i];
    }
    assert(invrep(s));
    return array;
}

stack stack_destroy(stack s)
{
    assert(invrep(s));
    free(s->elems);
    free(s);
    return s;
}
