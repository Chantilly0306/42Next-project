#include "push_swap.h"



void swap_all_piledata(t_pile *swap_up, t_pile *swap_down)
{
    ft_swap(swap_up->num, swap_down->num);
    ft_swap(swap_up->idx, swap_down->idx);
    ft_swap(swap_up->in_lis, swap_down->in_lis);
}
