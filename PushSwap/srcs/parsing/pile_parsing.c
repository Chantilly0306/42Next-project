#include "push_swap.h"

void pile_fill(t_data *data, t_pile_data *pile)
{
    long int num;

    while (data->nb_start && *data->nb_start)
    {
        while (*data->nb_start == ' ')
            data->nb_start++;
        if (*data->nb_start == '\0')
            break ;
        data->nb_end = ft_strchr(data->nb_start, ' ');
        // ft_printf("%s\n", data->nb_start);
        num = ft_atol(data->nb_start);
        // ft_printf("%i\n", num);
        if (num == LONG_MAX || is_double(num, pile) || num < INT_MIN || num > INT_MAX)
            error_exit(data, pile);
        if (num == LONG_MIN)
            break ;
        if (!pile_newadd(pile, num))
            error_exit(data, pile);
        // print_pile(pile->a, "pile file\n");
        if (data->nb_end != NULL)
            data->nb_start = data->nb_end + 1;
        else
            data->nb_start = NULL;
        data->nb_end = NULL;
    }
}

void pile_parsing(t_data *data, t_pile_data *pile)
{
    int i;

    i = data->start_idx;
    while (i < data->ac)
    {
        data->nb_start = data->av[i];
        pile_fill(data, pile);
        i++;
    }
    pile_to_tab(data, pile);
    bench_data_init(data, pile);
    pile_index(data, pile);
    pile_lis(data, pile);
}
