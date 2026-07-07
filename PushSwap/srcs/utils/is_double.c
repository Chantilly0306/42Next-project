#include "push_swap.h"

int is_double(long int num, t_pile_data *pile)
{
    t_pile *tmp;

    tmp = pile->a;
    while (tmp)
    {
        if (tmp->num == num)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}
