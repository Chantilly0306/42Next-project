/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_secure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 22:26:37 by lynlauro          #+#    #+#             */
/*   Updated: 2026/07/01 04:41:59 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_write_secure(t_printf_data *data, const char *s, size_t len)
{
	ssize_t	res;

	if (data->error == 1)
		return ;
	res = write(1, s, len);
	if (res == -1)
	{
		data->error = 1;
		return ;
	}
	data->count += (int)res;
}
