#include "push_swap.h"

void reverse_rotate_a(t_pile_data *pile_data)
{
    pile_data->first_a = pile_data->last_a;
    pile_data->last_a = pile_data->first_a->prev;
    pile_data->a = pile_data->first_a;
}

void reverse_rotate_b(t_pile_data *pile_data)
{
    pile_data->first_b = pile_data->last_b;
    pile_data->last_b = pile_data->first_b->prev;
    pile_data->b = pile_data->first_b;
}
