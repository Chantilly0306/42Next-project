#include "push_swap.h"

void push_to_b(t_pile_data *pile_data)
{
    t_pile *tmp;

    tmp = pile_data->first_a;
    pile_data->first_a = pile_data->first_a->next;
    pile_data->first_a->prev = pile_data->last_a;
    pile_data->last_a->next = pile_data->first_a;
    pile_data->a = pile_data->first_a;
    tmp->next = pile_data->first_b;
    tmp->prev = pile_data->last_b;
    pile_data->first_b->prev = tmp;
    pile_data->last_b->next = tmp;
    pile_data->first_b = tmp;
    pile_data->b = pile_data->first_b;
    pile_data->a_len--;
    pile_data->b_len++;
}

void push_to_a(t_pile_data *pile_data)
{
    t_pile *tmp;

    tmp = pile_data->first_b;
    pile_data->first_b = pile_data->first_b->next;
    pile_data->first_b->prev = pile_data->last_b;
    pile_data->last_b->next = pile_data->first_b;
    pile_data->b = pile_data->first_b;
    tmp->next = pile_data->first_a;
    tmp->prev = pile_data->last_a;
    pile_data->first_a->prev = tmp;
    pile_data->last_a->next =tmp;
    pile_data->first_a = tmp;
    pile_data->a = pile_data->first_a;
    pile_data->b_len--;
    pile_data->a_len++;
}
