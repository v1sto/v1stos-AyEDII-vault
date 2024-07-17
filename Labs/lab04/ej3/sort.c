/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y)
{
    return (x->rank <= y->rank);
}

bool array_is_sorted(player_t atp[], unsigned int length)
{
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i]))
    {
        i++;
    }
    return (i == length);
}

void swap(player_t a[], unsigned int i, unsigned int j)
{
    player_t aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

static unsigned int partition2(player_t a[], unsigned int izq, unsigned int der)
{
    unsigned int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    while (i <= j)
    {
        if (!goes_before(a[i], a[ppiv]) && !goes_before(a[ppiv], a[j]))
        {
            swap(a, i, j);
        }
        if (goes_before(a[i], a[ppiv]))
        {
            i++;
        }
        if (goes_before(a[ppiv], a[j]))
        {
            j--;
        }
    }
    swap(a, ppiv, j);
    ppiv = j;
    return ppiv;
}

static void quick_sort_rec2(player_t a[], unsigned int izq, unsigned int der)
{
    if (der > izq)
    {
        unsigned int ppiv = partition2(a, izq, der);
        if (ppiv != 0)
        {
            quick_sort_rec2(a, izq, ppiv - 1);
            quick_sort_rec2(a, ppiv + 1, der);
        }
    }
}

void sort(player_t a[], unsigned int length)
{
    quick_sort_rec2(a, 0, (length == 0) ? 0 : length - 1);
}
