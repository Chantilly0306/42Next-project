#include "push_swap.h"

void print_pile(t_pile *pile, const char *s)
{
    t_pile *tmp;

    tmp = pile;
    if(!pile)
        ft_printf("pile is empty");
    if (s)
        ft_printf("%s", s);
    while (tmp)
    {
        ft_printf(" num : ");
        ft_printf(" %i - ", tmp->num);
        tmp = tmp->next;
    }
    ft_printf(" NULL\n");
}

void print_pile_idx(t_pile *pile, const char *s)
{
    t_pile *tmp;

    tmp = pile;
    if(!pile)
        ft_printf("pile is empty");
    if (s)
        ft_printf("%s", s);
    ft_printf(" num : ");
    while (tmp)
    {
        ft_printf(" %i - ", tmp->num);
        tmp = tmp->next;
    }
    ft_printf(" NULL\n");
    tmp = pile;
    ft_printf(" idx : ");
    while (tmp)
    {
        ft_printf(" %i - ", tmp->idx);
        tmp = tmp->next;
    }
    ft_printf(" NULL\n");
}

void print_pile_lis(t_pile *pile, const char *s)
{
    t_pile *tmp;

    tmp = pile;
    if(!pile)
        ft_printf("pile is empty");
    if (s)
        ft_printf("%s", s);
    ft_printf(" num : ");
    while (tmp)
    {
        ft_printf(" %i - ", tmp->num);
        tmp = tmp->next;
    }
    ft_printf(" NULL\n");
    tmp = pile;
    ft_printf(" idx : ");
    while (tmp)
    {
        ft_printf(" %i - ", tmp->idx);
        tmp = tmp->next;
    }
    ft_printf(" NULL\n");
    tmp = pile;
    ft_printf(" lis : ");
    while (tmp)
    {
        ft_printf(" %i - ", tmp->in_lis);
        tmp = tmp->next;
    }
    ft_printf(" NULL\n");
}

void print_lis(t_lis *lis, const char *s)
{
    t_lis *tmp = lis;
    if(!lis)
        ft_printf("lis is empty");
    if (s)
        ft_printf("%s", s);
    ft_printf(" num : ");
    while (tmp)
    {
        ft_printf(" %i - ", tmp->lis_cur->num);
        tmp = tmp->lis_next;
    }
    ft_printf(" NULL\n");
    tmp = lis;
    ft_printf(" idx : ");
    while (tmp)
    {
        ft_printf(" %i - ", tmp->lis_cur->idx);
        tmp = tmp->lis_next;
    }
    ft_printf(" NULL\n");
}
