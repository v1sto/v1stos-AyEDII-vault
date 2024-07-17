#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb
{
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b)
{
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b)
{
    return a < b;
}

static bool rgt_ord(abb_elem e, abb tree)
{
    bool rgt = true;
    if (tree != NULL)
    {
        rgt = elem_less(e, tree->elem) && rgt_ord(e, tree->left) && rgt_ord(e, tree->right);
    }
    return rgt;
}
static bool lft_ord(abb_elem e, abb tree)
{
    bool lft = true;
    if (tree != NULL)
    {
        lft = elem_less(tree->elem, e) && lft_ord(e, tree->left) && lft_ord(e, tree->right);
    }
    return lft;
}

static bool invrep(abb tree)
{
    bool res = true;
    if (tree != NULL)
    {
        res = lft_ord(tree->elem, tree->left) && rgt_ord(tree->elem, tree->right) && invrep(tree->left) && invrep(tree->right);
    }

    return res;
}

abb abb_empty(void)
{
    abb tree;
    tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e)
{
    assert(invrep(tree));
    if (tree == NULL)
    {
        tree = malloc(sizeof(struct _s_abb));
        tree->elem = e;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if (elem_less(e, tree->elem))
    {
        tree->left = abb_add(tree->left, e);
    }
    else if (elem_less(tree->elem, e))
    {
        tree->right = abb_add(tree->right, e);
    }
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree)
{
    bool is_empty = tree == NULL;
    assert(invrep(tree));
    /*
     * Needs implementation
     */
    return is_empty;
}

bool abb_exists(abb tree, abb_elem e)
{
    bool exists = false;
    assert(invrep(tree));
    if (tree == NULL)
    {
        return false;
    }
    else if (elem_less(e, tree->elem))
    {
        exists = abb_exists(tree->left, e);
    }
    else if (elem_less(tree->elem, e))
    {
        exists = abb_exists(tree->right, e);
    }
    else if (elem_eq(e, tree->elem))
    {
        return true;
    }
    assert(abb_length(tree) != 0 || !exists);
    return exists;
}

unsigned int abb_length(abb tree)
{
    unsigned int length = 0;
    assert(invrep(tree));
    if (!abb_is_empty(tree))
    {
        length = 1 + abb_length(tree->left);
        length += abb_length(tree->right);
    }
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e)
{
    assert(invrep(tree));
    if (tree == NULL)
    {
        return NULL;
    }
    else if (elem_less(e, tree->elem))
    {
        tree->left = abb_remove(tree->left, e);
    }
    else if (elem_less(tree->elem, e))
    {
        tree->right = abb_remove(tree->right, e);
    }
    else
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            tree = NULL;
        }
        else if (tree->left == NULL)
        {
            abb temp = tree;
            tree = tree->right;
            free(temp);
        }
        else if (tree->right == NULL)
        {
            abb temp = tree;
            tree = tree->left;
            free(temp);
        }
        else
        {
            abb_elem max_left = abb_max(tree->left);
            tree->elem = max_left;
            tree->left = abb_remove(tree->left, max_left);
        }
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}

abb_elem abb_root(abb tree)
{
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree)
{
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    abb aux = tree;
    while (aux->right != NULL)
    {
        aux = aux->right;
    }
    max_e = aux->elem;
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree)
{
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    abb aux = tree;
    while (aux->left != NULL)
    {
        aux = aux->left;
    }
    min_e = aux->elem;
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree, abb_ordtype ord)
{
    assert(invrep(tree) && (ord == ABB_IN_ORDER ||
                            ord == ABB_PRE_ORDER ||
                            ord == ABB_POST_ORDER));
    if (tree != NULL)
    {
        if (ord == ABB_IN_ORDER)
        { // no longer Implementing in-order as default
            abb_dump(tree->left, ord);
            printf("%d ", tree->elem);
            abb_dump(tree->right, ord);
        }
        else if (ord == ABB_POST_ORDER)
        {
            abb_dump(tree->left, ord);
            abb_dump(tree->right, ord);
            printf("%d ", tree->elem);
        }
        else if (ord == ABB_PRE_ORDER)
        {
            printf("%d ", tree->elem);
            abb_dump(tree->left, ord);
            abb_dump(tree->right, ord);
        }
    }
}

abb abb_destroy(abb tree)
{
    assert(invrep(tree));
    if (tree == NULL)
    {
        return NULL;
    }
    tree->left = abb_destroy(tree->left);
    tree->right = abb_destroy(tree->right);
    free(tree);
    tree = NULL;
    assert(tree == NULL);
    return tree;
}
