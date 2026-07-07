/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 23:15:44 by lynlauro          #+#    #+#             */
/*   Updated: 2026/07/01 04:44:17 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

unsigned long int	ft_absolute(int value)
{
	if (value < 0)
		return ((unsigned long int)(-(long long)value));
	return ((unsigned long int)value);
}

