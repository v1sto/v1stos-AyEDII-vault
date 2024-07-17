#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

struct _node
{
    list_elem value;
    struct _node *next;
};

/* Constructors */
list empty(void)
{
    return NULL;
}

list addl(list l, int e)
{
    struct _node *new_node = malloc(sizeof(struct _node));
    new_node->value = e;
    new_node->next = l;
    return new_node;
}

/* Operations */
bool is_empty(list l)
{
    return (l == NULL);
}

//{- PRE: not is_empty(l) -}
list_elem head(list l)
{
    assert(!is_empty(l));
    return l->value;
}

//{- PRE: not is_empty(l) -}
list tail(list l)
{
    assert(!is_empty(l));
    return l->next;
}

list addr(list l, int e)
{
    struct _node *new_node = malloc(sizeof(struct _node));
    new_node->value = e;
    new_node->next = NULL;
    struct _node *laux = l;
    if (!is_empty(l))
    {
        while (laux->next != NULL)
        {
            laux = laux->next;
        }
        laux->next = new_node;
    }
    else
    {
        l = new_node;
    }
    return l;
}

int length(list l)
{
    int n = 0;
    struct _node *q;
    q = l;
    while (q != NULL)
    {
        q = q->next;
        n++;
    }
    return n;
}

list concat(list l1, list l2)
{
    struct _node *q = l1;
    if (!(is_empty(l1)))
    {
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = l2;
    }
    else
    {
        l1 = l2;
    }
    return l1;
}

//{- PRE: length(l) > n -}
list_elem index(list l, int n)
{
    assert(length(l) > n);
    int i = 0;
    struct _node *q;
    q = l;
    while (q->next != NULL && i < n)
    {
        q = q->next;
        i++;
    }
    return q->value;
}

void take(list l, int a)
{
    struct _node *q = l;
    int i = 0;
    if (a < length(l))
    {
        while (q != NULL && i < a)
        {
            q = q->next;
            i++;
        }
        destroy(q);
    }
    else
    {
        l = q;
    }
}

void drop(list l, int a)
{
    struct _node *q = l;
    int i = 0;
    if (a < length(l))
    {
        while (q != NULL && i < a)
        {
            q = q->next;
            i++;
        }
        l = q;
    }
    else
    {
        destroy(q);
    }
}

list copy_list(list l)
{
    list copy = NULL, p;
    p = l;
    if (is_empty(l))
    {
        return copy;
    }
    else
    {
        copy = addr(copy, l->value);
        p = p->next;
        while (p != NULL)
        {
            copy = addr(copy, p->value);
            p = p->next;
        }
        return copy;
    }
}

void destroy(list l)
{
    struct _node *p;
    while (l != NULL)
    {
        p = l;
        l = l->next;
        free(p);
    }
}
