#include "push_swap.h"

void pile_lis_index(t_lis *final_lis)
{
	while(final_lis)
	{
		final_lis->lis_cur->in_lis = 1;
		final_lis = final_lis->lis_next;
	}
}

void create_lis(t_pile_data *pile, t_lis *lis)
{
    t_pile *cur;
    t_pile *next;
    t_lis *tmp;

    cur = lis->lis_cur;
    next = get_next(lis->lis_cur,pile->a);
    tmp = lis;
    while (next != lis->lis_start->lis_cur)
    {
        if (cur->idx < next->idx)
        {
            lis_new_add(tmp, next);
            tmp = tmp->lis_next;
            cur = next;
            lis->lis_len++;
        }
        else if (tmp->lis_prev && next->idx > tmp->lis_prev->lis_cur->idx && next->idx < cur->idx)
        {
            tmp->lis_cur = next;
            cur = next;
        }
        next = get_next(next, pile->first_a);
    }
    print_lis(lis, "print LIS created\n");
}

void pile_lis(t_data *data, t_pile_data *pile)
{
    t_lis_data lis_data;
    t_pile *tmp;
    int i;

    lis_tab_init(&lis_data, pile);
    tmp = pile->a;
    i = 0;
    while(tmp)
    {
        lis_init(&lis_data.tab_lis[i], tmp);
		create_lis(pile, &lis_data.tab_lis[i]);
		if (lis_data.tab_lis[i].lis_len > lis_data.max_lis_len)
		{
			lis_data.idx_max_lis = i;
			lis_data.pile_max_lis = &lis_data.tab_lis[i];
			lis_data.max_lis_len = lis_data.tab_lis[i].lis_len;
		}
        tmp = tmp->next;
        i++;
    }
	pile_lis_index(lis_data.pile_max_lis);
    data->in_lis_total = lis_data.max_lis_len;
    print_pile_lis(pile->a, "final lis\n");
    pile->lis_len = lis_data.max_lis_len;
}
