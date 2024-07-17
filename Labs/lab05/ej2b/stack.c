#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _node
{
    stack_elem value;
    struct _node *next;
};
struct _s_stack
{
    struct _node *stack;
    unsigned int length;
};

stack stack_empty()
{
    stack s = malloc(sizeof(struct _s_stack));
    if (s == NULL)
    {
        return NULL;
    }
    s->stack = NULL;
    s->length = 0;
    return s;
}

stack stack_push(stack s, stack_elem e)
{
    struct _node *new_node = NULL;
    new_node = malloc(sizeof(struct _node));
    new_node->value = e;
    new_node->next = s->stack;
    s->stack = new_node;
    s->length++;
    return s;
}

stack stack_pop(stack s)
{
    assert(!stack_is_empty(s));
    struct _node *aux = NULL;
    aux = s->stack;
    s->stack = (s->stack)->next;
    s->length = s->length - 1;
    aux->next = NULL;
    free(aux);
    aux = NULL;
    return s;
}

unsigned int stack_size(stack s)
{
    return s->length;
}

bool stack_is_empty(stack s)
{
    return (s->length == 0);
}

stack_elem stack_top(stack s)
{
    assert(!stack_is_empty(s));
    return (s->stack)->value;
}

stack_elem *stack_to_array(stack s)
{
    if (stack_is_empty(s))
    {
        return NULL;
    }
    stack_elem *st_array = calloc(stack_size(s), sizeof(stack_elem));
    struct _node *aux = NULL;
    aux = s->stack;
    for (unsigned int i = 0; i < stack_size(s); i++)
    {
        st_array[stack_size(s) - 1 - i] = aux->value;
        aux = aux->next;
    }
    return st_array;
}

stack stack_destroy(stack s)
{
    struct _node *aux = NULL;
    aux = s->stack;
    while (!stack_is_empty(s))
    {
        s->stack = s->stack->next;
        aux->next = NULL;
        free(aux);
        aux = s->stack;
    }
    free(s);
    return s;
}
