/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:46:11 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:46:12 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t ft_strlcat(char *dst, const char *src, size_t siz)
{
    size_t len;

    len = 0;
    while (dst[len] && len < siz)
        len++;
    return (len + ft_strlcpy(dst + len, src, siz - len));
}
