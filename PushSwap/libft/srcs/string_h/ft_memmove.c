/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:45:30 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:45:31 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void *ft_memmove(void *dst, const void *src, size_t n)
// {
//     size_t len;

//     if(!dst && !src)
//         return (dst);
//     len = 0;
//     if(dst < src)
//         while(len < n)
//         {
//             *((unsigned char *)dst + len) = *((unsigned char *)src + len);
//             len ++;
//         }
//     else
//         while(n--)
//             *((unsigned char *) dst + n) = *((unsigned char *)src + n);
//     return (dst);
// }

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	if (!dst && !src)
		return (dst);
	if (dst == src)
		return (dst);
	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	if (dst < src)
		while (n--)
			*tmp_dst++ = *tmp_src++;
	else
		while (n--)
			tmp_dst[n] = tmp_src[n];
	return (dst);
}
