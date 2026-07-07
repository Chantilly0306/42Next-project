/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:45:23 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:45:24 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int ft_memcmp(const void *s1, const void *s2, size_t n)
// {
//     size_t len;

//     len = 0;
//     while (len < n)
//     {
//         if(*((unsigned char *)s1 + len) != *((unsigned char *)s2 + len))
//             return (*((unsigned char *)s1 + len) - *((unsigned char *)s2
//		+ len));
//         len++;
//     }
//     return (0);
// }

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*tmp_s1 != *tmp_s2)
			return (*tmp_s1 - *tmp_s2);
		tmp_s1++;
		tmp_s2++;
	}
	return (0);
}
