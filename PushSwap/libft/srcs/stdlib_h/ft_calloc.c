/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:44:57 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:44:58 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*s;

	if (n && (size > (SIZE_MAX / n)))
		return (NULL);
	s = (void *)malloc(size * n);
	if (!s)
		return (NULL);
	ft_bzero(s, (size * n));
	return (s);
}
