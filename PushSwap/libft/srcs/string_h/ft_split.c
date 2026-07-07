/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:45:45 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:45:46 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_2d(void **content, size_t size)
{
	size_t	i;

	i = 0;
	if (!content)
		return (NULL);
	while (i < size)
		free(content[i++]);
	free(content);
	content = NULL;
	return (content);
}

static char	**ft_fill_array(char const *s, char **arr, char c)
{
	int		i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len > 0)
		{
			arr[i] = ft_substr(s, 0, len);
			if (!arr[i])
				return (ft_free_2d((void **)arr, i));
			i++;
		}
		s += len;
	}
	return (arr);
}

static unsigned int	ft_count(char const *s, char c)
{
	unsigned int	count;
	char			*tmp;

	count = 0;
	tmp = (char *)s;
	while (*tmp)
	{
		while (*tmp && *tmp == c)
			tmp++;
		if (*tmp)
			++count;
		while (*tmp && *tmp != c)
			tmp++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;

	if (!s)
		return (NULL);
	dst = NULL;
	dst = (char **)ft_calloc(ft_count(s, c) + 1, sizeof(char *));
	if (!dst)
		return (NULL);
	return (ft_fill_array(s, dst, c));
}
