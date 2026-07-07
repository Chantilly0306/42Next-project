/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dispatch_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 23:26:43 by lynlauro          #+#    #+#             */
/*   Updated: 2026/07/02 06:35:55 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft_printf.h"

void	ft_print_s(t_printf_data *data, va_list arg)
{
	char	*s;

	s = (char *)va_arg(arg, char *);
	ft_puts_data(data, (const char *)s);
}

void	ft_print_c(t_printf_data *data, va_list arg)
{
	char	c;

	c = (char)va_arg(arg, int);
	ft_putc_data(data, c);
}

void	ft_print_pc(t_printf_data *data, va_list arg)
{
	(void)arg;
	ft_write_secure(data, "%", 1);
}

void	ft_print_i(t_printf_data *data, va_list arg)
{
	int					i;
	unsigned long int	val;
	// if (data->precision->u_long)
	// {
	// 	data->sub_tab[U_LONG_INT](data, arg);
	// 	return ;
	// }
	i = (int)va_arg(arg, int);
	if (i < 0)
		ft_putc_data(data, '-');
	val = ft_absolute(i);
	ft_putuli_data(data, val, BASE_DEC, DEC);
}

void	ft_print_u(t_printf_data *data, va_list arg)
{
	unsigned int	u;

	u = (unsigned int)va_arg(arg, unsigned int);
	ft_putuli_data(data, u, (unsigned long int) BASE_DEC, DEC);
}
