#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack
{
    stack_elem value;
    struct _s_stack *next;
};

stack stack_empty()
{

    return NULL;
}

stack stack_push(stack s, stack_elem e)
{
    struct _s_stack *new_node = malloc(sizeof(struct _s_stack));
    new_node->value = e;
    new_node->next = s;
    return new_node;
}

stack stack_pop(stack s)
{
    assert(!stack_is_empty(s));
    struct _s_stack *s2 = s;
    s = s->next;
    free(s2);
    return s;
}

unsigned int stack_size(stack s)
{
    struct _s_stack *s2 = s;
    unsigned int i = 0;
    while (s2 != NULL)
    {
        s2 = s2->next;
        i++;
    }
    return i;
}

stack_elem stack_top(stack s)
{
    assert(!stack_is_empty(s));
    return s->value;
}

bool stack_is_empty(stack s)
{
    return s == NULL;
}

stack_elem *stack_to_array(stack s)
{
    if (stack_is_empty(s))
    {
        return NULL;
    }
    stack_elem *st_array = calloc(stack_size(s), sizeof(stack_elem));
    struct _s_stack *s2 = s;
    size_t i = stack_size(s);
    while (!stack_is_empty(s2) && i > 0)
    {
        st_array[i - 1] = s2->value;
        s2 = s2->next;
        i--;
    }
    return st_array;
}

stack stack_destroy(stack s)
{
    if (!stack_is_empty(s))
    {
        stack_destroy(s->next);
        free(s);
    }
    return s;
}