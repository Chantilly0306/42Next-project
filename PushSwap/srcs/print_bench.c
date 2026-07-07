#include "push_swap.h"
#include "stdio.h"

void print_bench_data(t_bench_data *bench_data)
{
	ft_printf("\n");
	ft_printf("BENCH DATA\n");
	ft_printf("mistakes :	%i\n", bench_data->mistakes);
	ft_printf("pairs :		%i\n", bench_data->pairs);
	printf("disorder :	%.2f\n", bench_data->disorder);
	printf("disorder %%:	%.2f %%\n", bench_data->disorder_percent);
	ft_printf("\n");
}

void	print_bench_report(t_data *data)
{
	t_bench_data	*b;
	char			*strategy_str;

	b = data->bench_data;
	strategy_str = "Complex / O(n log n)";
	if (data->strategy == ADAPTATIVE)
	{
		if (b->disorder < 0.2)
			strategy_str = "Adaptive / O(n)";
		else if (b->disorder < 0.5)
			strategy_str = "Adaptive / O(n√n)";
		else
			strategy_str = "Adaptive / O(n log n)";
	}
	else if (data->strategy == SIMPLE)
		strategy_str = "Simple / O(n^2)";
	else if (data->strategy == MEDIUM)
		strategy_str = "Medium / O(n√n)";
	print_report("[bench] disorder:  %.2f%%\n", b->disorder_percent);
	print_report("[bench] strategy:  %s\n", strategy_str);
	print_report("[bench] total_ops: %d\n", b->total_ops);
	print_report("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		b->sa, b->sb, b->ss, b->pa, b->pb);
	print_report("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		b->ra, b->rb, b->rr, b->rra, b->rrb, b->rrr);
}
