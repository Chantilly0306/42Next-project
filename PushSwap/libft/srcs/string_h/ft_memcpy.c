/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:45:27 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:45:35 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void *ft_memcpy(void *dst, const void *src, size_t n)
// {
//     size_t len;

//     if(!dst && !src)
//         return (dst);
//     len = 0;
//     while (len < n)
//     {
//         *((unsigned char *)dst + len) = *((unsigned char *)src + len);
//         len++;
//     }
//     return (dst);
// }

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	if (!dst && !src)
		return (dst);
	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	while (n--)
		*tmp_dst++ = *tmp_src++;
	return (dst);
}
