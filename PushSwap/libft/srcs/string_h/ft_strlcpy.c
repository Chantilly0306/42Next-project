/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:46:15 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:46:16 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	len;

	len = 0;
	if (siz)
	{
		while (*(src + len) && len < (siz - 1))
		{
			*(dst + len) = *(src + len);
			len++;
		}
		*(dst + len) = '\0';
	}
	return (ft_strlen(src));
}
