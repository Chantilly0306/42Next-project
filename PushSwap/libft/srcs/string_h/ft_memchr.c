/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:45:18 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:45:20 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void *ft_memchr(const void *s, int c, size_t n)
// {
//     size_t len;

//     len = 0;
//     while (len < n)
//     {
//         if( *((unsigned char *)s + len) == (unsigned char) c)
//             return (((void *)s + len));
//         len++;
//     }
//     return (NULL);
// }

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n--)
	{
		if (*tmp == (unsigned char)c)
			return ((void *)(uintptr_t)tmp);
		tmp++;
	}
	return (NULL);
}
