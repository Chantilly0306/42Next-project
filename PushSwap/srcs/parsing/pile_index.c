#include "push_swap.h"

void index_to_pile(t_pile_tab *tab, size_t tab_len)
{
    size_t i;

    i = 0;
    while (i < tab_len)
    {
        if (tab[i].pile_ptr)
            tab[i].pile_ptr->idx = i;
        i++;
    }
}

void pile_index(t_data *data, t_pile_data *pile)
{
    print_tab(data->tab, pile->a_len, "transform pile to tab\n");
    quick_sort(data->tab, 0, pile->a_len - 1);
    print_tab(data->tab, pile->a_len, "tab after quicksort\n");
    index_to_pile(data->tab, pile->a_len);
    print_pile_idx(pile->a, "pile indexation\n");
}
