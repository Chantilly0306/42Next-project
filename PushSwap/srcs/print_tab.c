#include "push_swap.h"

void print_tab(t_pile_tab *tab, size_t len, const char *s)
{
    if(!tab)
    {
        ft_printf("tab is empty");
        return ;
    }
    if (s)
        ft_printf("%s", s);
    for(size_t i = 0; i < len; i++)
        ft_printf(" %i - ", tab[i].val);
    ft_printf(" NULL\n");
    for(size_t i = 0; i < len; i++)
        ft_printf(" %i - ", i);
    ft_printf(" NULL\n");
}
