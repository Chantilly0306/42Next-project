#include "push_swap.h"

t_pile *get_next(t_pile *current, t_pile *first)
{
	if(!current->next)
		return (first);
	return (current->next);
}

t_pile *get_prev(t_pile *current, t_pile *last)
{
	if (!current->prev)
		return (last);
	return (current->prev);
}
