/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuli_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 23:29:27 by lynlauro          #+#    #+#             */
/*   Updated: 2026/07/01 04:41:45 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_putuli_data(t_printf_data *data, unsigned long int value,
		unsigned long int base, char *s_base)
{
	if (base <= 1 || s_base == NULL || data->error == 1)
		return ;
	if (value >= base)
		ft_putuli_data(data, value / base, base, s_base);
	ft_putc_data(data, s_base[value % base]);
}
