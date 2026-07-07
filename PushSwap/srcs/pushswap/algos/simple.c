#include "push_swap.h"

int	step_operation(t_data *data, t_pile_data *pile, char *step)
{
	if (!ft_strcmp(step, "pa"))
		push_to_a(pile);
	else if (!ft_strcmp(step, "pb"))
		push_to_b(pile);
	else if (!ft_strcmp(step, "ra"))
		rotate_a(pile);
	else if (!ft_strcmp(step, "rb"))
		rotate_b(pile);
	else if (!ft_strcmp(step, "rra"))
		reverse_rotate_a(pile);
	else if (!ft_strcmp(step, "rrb"))
		reverse_rotate_b(pile);
	if (data->is_bench != 1)
		ft_printf("%s\n", step);
	return (1);
}

int	find_min_pos(t_pile *start, size_t len)
{
	t_pile	*curr;
	int		min_idx;
	int		min_pos;
	int		curr_pos;

	curr = start;
	min_idx = curr->idx;
	min_pos = 0;
	curr_pos = 0;
	while (curr_pos < (int)len)
	{
		if (curr->idx < min_idx)
		{
			min_idx = curr->idx;
			min_pos = curr_pos;
		}
		curr = curr->next;
		curr_pos++;
	}
	return (min_pos);
}

static void	rotate_or_reverse(t_data *data, t_pile_data *pile, int pos)
{
	int	i;

	i = 0;
	if (pos <= (int)pile->a_len / 2)
	{
		while (i < pos)
		{
			data->bench_data->ra += step_operation(data, pile, "ra");
			i++;
		}
	}
	else
	{
		while (i < (int)pile->a_len - pos)
		{
			data->bench_data->ra += step_operation(data, pile, "rra");
			i++;
		}
	}
}

void	sort_selection(t_data *data, t_pile_data *pile)
{
	int	min_pos;

	while (pile->a_len > 0)
	{
		min_pos = find_min_pos(pile->first_a, pile->a_len);
		rotate_or_reverse(data, pile, min_pos);
		data->bench_data->pb += step_operation(data, pile, "pb");
	}
	while (pile->b_len > 0)
		data->bench_data->pa += step_operation(data, pile, "pa");
}
