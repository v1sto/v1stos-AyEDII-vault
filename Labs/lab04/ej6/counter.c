#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "counter.h"

struct _counter
{
    unsigned int count;
};

counter counter_init(void)
{
    counter init = malloc(sizeof(struct _counter));
    init->count = 0;
    assert(counter_is_init);
    return init;
}

void counter_inc(counter c)
{
    c->count++;
}

bool counter_is_init(counter c)
{
    return c->count == 0;
}

void counter_dec(counter c)
{
    assert(!counter_is_init(c));
    c->count--;
}

counter counter_copy(counter c)
{
    counter copy = malloc(sizeof(struct _counter));
    copy->count = c->count;
    return copy;
}

void counter_destroy(counter c)
{
    free(c);
}
