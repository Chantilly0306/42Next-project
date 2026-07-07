/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 23:29:01 by lynlauro          #+#    #+#             */
/*   Updated: 2026/07/01 04:41:27 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_puts_data(t_printf_data *data, const char *s)
{
	if (data->error == 1)
		return ;
	if (!s)
	{
		ft_puts_data(data, "(null)");
		return ;
	}
	ft_write_secure(data, s, ft_strlen(s));
}

