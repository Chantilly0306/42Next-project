/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:40:48 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:41:42 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_realloc(void **ptr, size_t old, size_t new)
{
	void *str;

	if (!ptr)
		return NULL;
	if (!new)
	{
		free(*ptr);
		*ptr = NULL;
		return (NULL);
	}
	if (*ptr && old == new)
		return (*ptr);
	str = ft_memset(malloc(new + 1), 0, new + 1);
	if (!str)
		return (NULL);
	if(*ptr)
	{
		if (old > new)
			old = new;
		ft_memcpy(str, *ptr, old);
		free(*ptr);
	}
	*ptr = str;
	return (*ptr);
}
