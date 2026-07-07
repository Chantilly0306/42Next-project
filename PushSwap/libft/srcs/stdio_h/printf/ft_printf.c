/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 23:21:38 by lynlauro          #+#    #+#             */
/*   Updated: 2026/07/02 02:08:07 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft_printf.h"

void	dispatcher(t_printf_data *data, va_list args)
{
	if (!data->end || !*(data->end + 1) || data->error == 1)
		return ;
	if (data->table[(int)(unsigned char)*(data->end + 1)])
		data->table[(int)(unsigned char)*(data->end + 1)](data, args);
	else
		ft_write_secure(data, data->end, 2);
	data->start = data->end + 2;
	data->end = NULL;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_printf_data	data;

	if (!format)
		return (-1);
	va_start(args, format);
	data_printf_init(&data, format);
	while (data.start && *data.start && !data.error)
	{
		data.end = ft_memchr((const void *)data.start, '%',
				ft_strlen(data.start));
		if (!data.end)
		{
			ft_write_secure(&data, data.start, ft_strlen(data.start));
			break ;
		}
		if (data.end > data.start)
			ft_write_secure(&data, data.start,
				(size_t)(data.end - data.start));
		dispatcher(&data, args);
	}
	if (data.error)
		return (-1);
	va_end(args);
	return (data.count);
}
