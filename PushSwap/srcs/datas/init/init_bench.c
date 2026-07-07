#include "push_swap.h"

void bench_data_init(t_data *data, t_pile_data *pile)
{
	size_t i;
	t_pile *tmp;

	i = 0;
	tmp = NULL;
	data->bench_data = (t_bench_data *)ft_calloc(1, sizeof(t_bench_data));
	while(i < pile->a_len)
	{
		tmp = data->tab[i].pile_ptr->next;
		while(tmp)
		{
			data->bench_data->pairs++;
			if(data->tab[i].pile_ptr->num > tmp->num)
				data->bench_data->mistakes++;
			tmp = tmp->next;
		}
		i++;
	}
	data->bench_data->disorder = (float)data->bench_data->mistakes / (float)data->bench_data->pairs;
	data->bench_data->disorder_percent = data->bench_data->disorder * 100.00;
	print_bench_data(data->bench_data);
}
