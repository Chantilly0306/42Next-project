#include "push_swap.h"

static void swap_tab(t_pile_tab *a, t_pile_tab *b)
{
    t_pile_tab tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

static int partition(t_pile_tab *tab, int low, int high)
{
    long int median;
    int i_prev_low;
    int i_low;

    median = tab[high].val;
    i_low = low;
    i_prev_low = low - 1;
    while (i_low < high)
    {
        if (tab[i_low].val < median)
        {
            i_prev_low++;
            swap_tab(&tab[i_prev_low], &tab[i_low]);
        }
        i_low++;
    }
    swap_tab(&tab[i_prev_low + 1], &tab[i_low]);
    return (i_prev_low + 1);
}

void quick_sort(t_pile_tab *tab, int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(tab, low, high);
        quick_sort(tab, low, pivot - 1);
        quick_sort(tab, pivot + 1, high);
    }
}
