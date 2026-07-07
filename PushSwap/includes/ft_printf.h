/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 23:22:21 by lynlauro          #+#    #+#             */
/*   Updated: 2026/07/02 05:17:46 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"
# include "libft_printf.h"

void	data_printf_init(t_printf_data *data, const char *format);
int		ft_printf(const char *format, ...);

#endif
