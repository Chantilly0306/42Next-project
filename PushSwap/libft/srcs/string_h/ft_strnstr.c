/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:46:32 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:46:33 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lil_len;

	i = 0;
	lil_len = ft_strlen(little);
	if (!lil_len)
		return ((char *)big);
	while (*(big + i) && (i + lil_len) <= len)
	{
		if ((*(big + i) == *little) && !ft_memcmp(big + i, little, lil_len))
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
