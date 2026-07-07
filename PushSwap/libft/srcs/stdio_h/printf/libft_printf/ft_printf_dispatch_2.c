/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dispatch_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 23:26:43 by lynlauro          #+#    #+#             */
/*   Updated: 2026/07/02 06:35:12 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft_printf.h"

void	ft_print_lx(t_printf_data *data, va_list arg)
{
	unsigned int	lx;

	lx = (unsigned int)va_arg(arg, unsigned int);
	ft_putuli_data(data, lx, (unsigned long int) BASE_HEX, L_HEX);
}

void	ft_print_ux(t_printf_data *data, va_list arg)
{
	unsigned int	ux;

	ux = (unsigned int)va_arg(arg, unsigned int);
	ft_putuli_data(data, ux, (unsigned long int) BASE_HEX, U_HEX);
}

void	ft_print_p(t_printf_data *data, va_list arg)
{
	void				*p;
	unsigned long int	val;

	p = (void *)va_arg(arg, void *);
	if (!p)
	{
		ft_puts_data(data, "(nil)");
		return ;
	}
	val = (unsigned long int)p;
	ft_puts_data(data, "0x");
	ft_putuli_data(data, val, BASE_HEX, L_HEX);
}

// void	ft_print_f(t_printf_data *data, va_list arg)
// {
// 	double i;
// 	double val;

// 	i = (double)va_arg(arg, double);
// 	if (i < 0)
// 		ft_putc_data(data, '-');
// 	ft_putdouble_data(data, val);
// }
