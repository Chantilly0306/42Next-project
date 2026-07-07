/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:46:20 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/25 00:41:39 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

    if (!str)
	{
        return (0);
	}
	len = 0;
	while (len[str])
		len++;
	return (len);
}

// size_t	ft_strlen(const char *str)
// {
// 	const char	*tmp;
// 	tmp = str;
// 	while (*tmp)
// 		tmp++;
// 	return ((size_t)(tmp - str));
// }
