/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_printf_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 23:26:24 by lynlauro          #+#    #+#             */
/*   Updated: 2026/07/02 06:43:30 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft_printf.h"

// static void table_init(t_printf_data *data)
// {
// 	data->sub_tab[4] = &ft_print_li;
// }

static void table_init(t_printf_data *data)
{
	data->table['%'] = &ft_print_pc;
	data->table['c'] = &ft_print_c;
	data->table['s'] = &ft_print_s;
	data->table['i'] = &ft_print_i;
	data->table['d'] = &ft_print_i;
	data->table['p'] = &ft_print_p;
	data->table['u'] = &ft_print_u;
	// data->table['f'] = &ft_print_f;
	data->table['x'] = &ft_print_lx;
	data->table['X'] = &ft_print_ux;
}

void	data_printf_init(t_printf_data *data, const char *format)
{
	ft_memset((void *)data, 0, sizeof(t_printf_data));
	data->start = format;
	// ft_memset((void *)data->flags, 0, sizeof(t_flags));
	ft_memset((void *)data->table, 0, 256);
	table_init(data);
	// ft_memset((void *)data->sub_tab, 0, 256);
	// sub_tab_init(data);
}
