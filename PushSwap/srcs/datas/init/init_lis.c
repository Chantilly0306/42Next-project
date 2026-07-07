#include "push_swap.h"

void lis_new_add(t_lis *prev, t_pile *cur)
{
	t_lis *new;

	new = (t_lis *)ft_calloc(1, sizeof(t_lis));
    new->lis_cur = cur;
    new->lis_start = prev->lis_start;
	new->lis_start->lis_end = new;
	new->lis_start->lis_len++;
    new->lis_prev = prev;
	prev->lis_next = new;
}

void lis_init(t_lis *tab_lis, t_pile *pile_a)
{
	tab_lis->lis_cur = pile_a;
	tab_lis->lis_len = 1;
	tab_lis->lis_start = tab_lis;
	tab_lis->lis_end = tab_lis;
}

void lis_tab_init(t_lis_data *lis_data, t_pile_data *pile)
{
    ft_memset(lis_data, 0, sizeof(t_lis_data));
    lis_data->pile_a = pile->a;
    lis_data->max_lis_len = 1;
    lis_data->tab_lis = ft_calloc(pile->a_len, sizeof(t_lis));
}
