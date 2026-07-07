#include "push_swap.h"

void rotate_a(t_pile_data *pile_data)
{
    pile_data->last_a  = pile_data->first_a;
    pile_data->first_a = pile_data->last_a->next;
    pile_data->a = pile_data->first_a;
}

void rotate_b(t_pile_data *pile_data)
{
    pile_data->last_b  = pile_data->first_b;
    pile_data->first_b = pile_data->last_b->next;
    pile_data->b = pile_data->first_b;
}
