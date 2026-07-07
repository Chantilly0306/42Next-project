/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 23:28:48 by lynlauro          #+#    #+#             */
/*   Updated: 2026/07/01 04:41:06 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_putc_data(t_printf_data *data, char c)
{
	if (data->error == 1)
		return ;
	ft_write_secure(data, (const char *)&c, 1);
}
