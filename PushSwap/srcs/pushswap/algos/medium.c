#include "push_swap.h"

static int	ft_sqrt(int number)
{
	int	i;

	i = 1;
	if (number <= 0)
		return (0);
	while (i * i <= number)
	{
		if (i * i == number)
			return (i);
		i++;
	}
	return (i - 1);
}

static int	find_max_pos(t_pile *start, size_t len)
{
	t_pile	*curr;
	int		max_idx;
	int		max_pos;
	int		curr_pos;

	curr = start;
	max_idx = curr->idx;
	max_pos = 0;
	curr_pos = 0;
	while (curr_pos < (int)len)
	{
		if (curr->idx > max_idx)
		{
			max_idx = curr->idx;
			max_pos = curr_pos;
		}
		curr = curr->next;
		curr_pos++;
	}
	return (max_pos);
}

static void	rotate_b_push_a(t_data *data, t_pile_data *pile, int pos)
{
	int	i;

	i = 0;
	if (pos <= (int)pile->b_len / 2)
	{
		while (i < pos)
		{
			data->bench_data->rb += step_operation(data, pile, "rb");
			i++;
		}
	}
	else
	{
		while (i < (int)pile->b_len - pos)
		{
			data->bench_data->rrb += step_operation(data, pile, "rrb");
			i++;
		}
	}
	data->bench_data->pa += step_operation(data, pile, "pa");
}

void	sort_chunk(t_data *data, t_pile_data *pile)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = ft_sqrt((int)pile->lis_len) * 1.5;
	while (pile->a_len > 0)
	{
		if (pile->first_a->idx <= i)
		{
			data->bench_data->pb += step_operation(data, pile, "pb");
			data->bench_data->rb += step_operation(data, pile, "rb");
			i++;
		}
		else if (pile->first_a->idx <= i + chunk)
		{
			data->bench_data->pb += step_operation(data, pile, "pb");
			i++;
		}
		else
			data->bench_data->ra += step_operation(data, pile, "ra");
	}
	while (pile->b_len > 0)
		rotate_b_push_a(data, pile, find_max_pos(pile->first_b, pile->b_len));
}
