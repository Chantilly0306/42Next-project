/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:45:38 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:45:39 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
		*((unsigned char *)s + len++) = (unsigned char)c;
	return (s);
}

// void *ft_memset(void *s, int c, size_t n)
// {
//     unsigned char *tmp_s;

//     if (!s || !n)
//         return ;
//     tmp_s = (unsigned char *)s;
//     while(n--)
//         *tmp_s++ = (unsigned char)c;
//     return (s);
// }
