/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:46:03 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:46:04 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(src);
	dst = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	return ((char *)ft_memcpy(dst, src, len + 1));
}

// char *ft_strdup(const char *src)
// {
//     char *dst;
//     size_t len;
//     len = ft_strlen(src);
//     dst = (char *)ft_calloc(len + 1, 1);
//     if (!dst)
//         return (NULL);
//     return (ft_strlcpy(dst, src, len + 1), dst);
// }
