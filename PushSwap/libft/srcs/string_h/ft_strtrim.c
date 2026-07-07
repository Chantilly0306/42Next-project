/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:46:39 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:46:40 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}

// char *ft_strtrim(char const *s1, char const *set)
// {
//     char *start;
//     char *end;

//     if(!s1 || !set)
//         return (NULL);
//     start = (char *)s1;
//     end = (char *)s1 + ft_strlen(s1);
//     while (*start && ft_strchr(set, *start))
//         start++;
//     while (end > start && ft_strchr(set, end - 1))
//         end--;
//     return (ft_substr(s1, start - s1, end - start));
// }
