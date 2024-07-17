#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

/* counter as a pointer to structs to guarantee encapsulation */
typedef struct _node *list;
typedef int list_elem;

/* Constructors */
list empty(void);

list addl(list l, int e);

/* Operations */
bool is_empty(list l);

list_elem head(list l);
//{- PRE: not is_empty(l) -}

list tail(list l);
//{- PRE: not is_empty(l) -}

list addr(list l, int e);

int length(list l);

list concat(list l1, list l2);

list_elem index(list l, int n);
//{- PRE: length(l) > n -}

void take(list l, int a);

void drop(list l, int a);

list copy_list(list l);

void destroy(list l);

#endif