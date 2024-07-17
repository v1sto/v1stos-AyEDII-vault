#include <stdio.h>
#include <assert.h>
#include "pair.h"

pair_t pair_new(int x, int y)
{
    pair_t new;
    new.fst = x;
    new.snd = y;
    return new;
}

int pair_first(pair_t p)
{
    int first = p.fst;
    return first;
}

int pair_second(pair_t p)
{
    int second = p.snd;
    return second;
}

pair_t pair_swapped(pair_t p)
{
    int aux = p.fst;
    p.fst = p.snd;
    p.snd = aux;
    return p;
}

pair_t pair_destroy(pair_t p)
{
    return p;
}
