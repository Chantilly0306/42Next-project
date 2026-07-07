#include "push_swap.h"

t_pile *pile_newadd(t_pile_data *pile, long int num)
{
    t_pile *new;

    new = (t_pile *)ft_calloc(1, sizeof(t_pile));
    if (!new)
        return (NULL);
    new->num = num;
    if (!pile->a)
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
    pile->a_len++;
    return (pile->a);
}
