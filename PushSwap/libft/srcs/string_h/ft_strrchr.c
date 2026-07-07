/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:46:36 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:46:37 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*last;

	if (!s)
		return (NULL);
	last = (unsigned char *)s + ft_strlen(s);
	while (last >= (unsigned char *)s)
	{
		if (*last == (unsigned char)c)
		{
			return ((char *)last);
		}
		--last;
	}
	return (NULL);
}

// char *ft_strrchr(const char *s, int c)
// {
// 	int i;

// 	if (!s)
// 		return (NULL);
// 	//  if (!c)
//     //      return ((char *)s);
// 	i = ft_strlen(s);
//     while (i >= 0)
//     {
// 		if (s[i] == (unsigned  char)c)
// 			return ((char *)s + i);
// 		i--;
//     }
//     return (NULL);
// }
