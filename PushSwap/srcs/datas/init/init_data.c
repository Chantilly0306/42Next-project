#include "push_swap.h"

void tag_ft_init(t_data *data)
{
    ft_memset((void *)data->tag_tab, 0, 6);
    // data->tag_tab[1] = &benchmark;
    data->tag_tab[2] = &algo_adaptative;
    data->tag_tab[3] = &sort_selection;
    data->tag_tab[4] = &sort_chunk;
    data->tag_tab[5] = &algo_complex;
}

int complex_and_bench_init(t_data *data, int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac)
    {
        if (!data->strategy || !data->is_bench)
        {
            if (ft_strcmp(av[i], "--simple") == 0)
                data->strategy = SIMPLE;
            else if (ft_strcmp(av[i], "--medium") == 0)
                data->strategy = MEDIUM;
            else if (ft_strcmp(av[i], "--complex") == 0)
                data->strategy = COMPLEX;
            else if (ft_strcmp(av[i], "--adaptative") == 0)
                data->strategy = ADAPTATIVE;
            else if (ft_strcmp(av[i], "--bench") == 0)
                data->is_bench = BENCH;
            else
                break ;
        }
        i++;
    }
    if (!data->strategy)
        data->strategy = ADAPTATIVE;
    return (i);
}

void    data_init(t_data *data, int ac, char **av)
{
    ft_memset((void *)data, 0, sizeof(t_data));
    if (!data)
        return ;
    data->ac = ac;
    data->av = av;
    data->start_idx = complex_and_bench_init(data, ac, av);
    if (data->start_idx < ac)
        data->nb_start = av[data->start_idx];
    tag_ft_init(data);
}
