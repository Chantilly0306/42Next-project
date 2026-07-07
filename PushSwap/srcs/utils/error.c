#include "push_swap.h"
#include <stdio.h>

void error_exit(t_data *data, t_pile_data *pile)
{
	(void)data;
	(void)pile;
	ft_printf("Error\n");
	// free_all_data(data);
	// free_all_piledata(pile);
	exit(EXIT_FAILURE);
}
