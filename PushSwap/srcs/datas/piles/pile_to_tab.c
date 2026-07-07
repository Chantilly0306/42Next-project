#include "push_swap.h"

void pile_to_tab(t_data *data, t_pile_data *pile)
{
    size_t i;
    t_pile *tmp;
    data->tab = (t_pile_tab *)ft_calloc(sizeof(t_pile_tab), pile->a_len);
    if (!data->tab)
        error_exit(data, NULL);
    i = 0;
    tmp = pile->a;
    while (tmp && i < pile->a_len)
    {
        data->tab[i].val = tmp->num;
        data->tab[i].pile_ptr = tmp;
        tmp = tmp->next;
        i++;
    }
    print_tab(data->tab, pile->a_len, "fonction pile_to_tab\n");
}
