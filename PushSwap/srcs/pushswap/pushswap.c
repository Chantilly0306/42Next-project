#include "push_swap.h"

void linked_to_circular(t_data *data, t_pile_data *pile)
{
    if(!data || !pile)
        error_exit(data, pile);
    pile->first_a->prev = pile->last_a;
    pile->last_a->next = pile->first_a;
}

void pushswap(t_data *data, t_pile_data *pile)
{
    if(!data || !pile)
        error_exit(data, pile);
    linked_to_circular(data, pile);
    data->tag_tab[(int)data->strategy](data, pile);

    if (data->is_bench == 1)
	{
		data->bench_data->total_ops = data->bench_data->sa + data->bench_data->sb
			+ data->bench_data->ss + data->bench_data->pa + data->bench_data->pb
			+ data->bench_data->ra + data->bench_data->rb + data->bench_data->rr
			+ data->bench_data->rra + data->bench_data->rrb + data->bench_data->rrr;
		
		print_bench_report(data);
	}
}
