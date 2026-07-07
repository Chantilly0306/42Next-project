/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:44:41 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:44:42 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putendl_fd(char *str, int fd)
{
    if (str)
    {
        ft_putstr_fd(str, fd);
        ft_putchar_fd('\n', fd);
    }
}
