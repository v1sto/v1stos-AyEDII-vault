#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "pair.h"

struct s_pair_t
{
    int fst;
    int snd;
};

pair_t pair_new(int x, int y)
{
    pair_t new = malloc(sizeof(struct s_pair_t));
    new->fst = x;
    new->snd = y;
    return new;
}

int pair_first(pair_t p)
{
    assert(p != NULL);
    return p->fst;
}

int pair_second(pair_t p)
{
    assert(p != NULL);
    return p->snd;
}

pair_t pair_swapped(pair_t p)
{
    assert(p != NULL);
    pair_t aux = malloc(sizeof(struct s_pair_t));
    aux->fst = p->snd;
    aux->snd = p->fst;
    return aux;
}

pair_t pair_destroy(pair_t p)
{
    free(p);
    return NULL;
}
