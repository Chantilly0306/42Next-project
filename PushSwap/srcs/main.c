#include "push_swap.h"

int main(int ac, char **av)
{
    t_data data;
    t_pile_data pile;

    if (ac < 2 || !av[1] || !*av[1])
        return (EXIT_FAILURE);

    data_init(&data, ac, av);
    if (data.start_idx >= ac) // if there is no number after flags
        return (EXIT_FAILURE);
    pile_init(&pile);
    pile_parsing(&data, &pile);
    print_pile_lis(pile.a, "final pile a\n");
    // pushswap(&data, &pile);
    return (EXIT_SUCCESS);
}

// when pushswap began close the double link list 
// sa = swap(first & first->ne xt)
// pa = addfront(a -> b)
// ra = first_a = last_a / last_a = first_a prev / pile_a = first_a
// rra = last_a = first_a / first_a = last_a next / pile_a = first_a
