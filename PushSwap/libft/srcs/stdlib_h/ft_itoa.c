/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:45:02 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:45:03 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(long n)
{
	int	len;

	len = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_fill_string(char *s, long n, int len)
{
	if (n == 0)
		return (s);
	s[len] = n % 10 + '0';
	return (ft_fill_string(s, n / 10, len - 1));
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*s;
	long	num;

	num = n;
	len = ft_nlen(num);
	s = (char *)ft_calloc((len + 1), sizeof(char));
	if (!s)
		return (NULL);
	if (num == 0)
	{
		s[0] = '0';
		return (s);
	}
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	s = ft_fill_string(s, num, len - 1);
	return (s);
}
