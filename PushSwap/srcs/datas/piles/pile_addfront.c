#include "push_swap.h"

void *pile_a_addfront(t_pile_data *pile, t_pile *new)
{
    if (!new)
        return (NULL);
    if (!&pile->a)
    {
        pile->last_a = new;
    }
    else
    {
        pile->first_a->prev = new;
        new->next = pile->first_a;
    }
    pile->first_a = new;
    pile->a = new;
    pile->a_len++;
    pile->b_len--;
    return (pile->a);
}

void *pile_b_addfront(t_pile_data *pile, t_pile *new)
{
    if (!new)
        return (NULL);
    if (!&pile->b)
    {
        pile->last_b = new;
    }
    else
    {
        pile->first_b->prev = new;
        new->next = pile->first_b;
    }
    pile->first_b = new;
    pile->b = new;
    pile->a_len--;
    pile->b_len++;
    return (pile->b);
}

