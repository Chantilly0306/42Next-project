#include "push_swap.h"

void *pile_a_addback(t_pile_data *pile, t_pile *new)
{
    if (!new)
        return (NULL);
    if (!&pile->a)
    {
        pile->a = new;
        pile->first_a = new;
    }
    else
    {
        pile->last_a->next = new;
        new->prev = pile->last_a;
    }
    pile->last_a = new;
    return (pile->a);
}

void *pile_b_addback(t_pile_data *pile, t_pile *new)
{
    if (!new)
        return (NULL);
    if (!&pile->b)
    {
        pile->b = new;
        pile->first_b = new;
    }
    else
    {
        pile->last_b->next = new;
        new->prev = pile->last_b;
    }
    pile->last_b = new;
    return (pile->b);
}

