/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 23:29:43 by lynlauro          #+#    #+#             */
/*   Updated: 2026/07/02 06:43:19 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

# define DEC "0123456789"
# define L_HEX "0123456789abcdef"
# define U_HEX "0123456789ABCDEF"
# define BASE_DEC 10
# define BASE_HEX 16

struct			s_printf_data;
typedef void	(*t_dispatcher_ft)(struct s_printf_data *, va_list);

// typedef enum e_format
// {
// 	SHORT_INT = 1,
// 	U_SHORT_INT,
// 	SHORT_UX,
// 	LONG_INT,
// 	U_LONG_INT,
// 	LONG_U_HEX,
// 	DOUBLE,
// 	LONG_LONG_INT,
// 	U_LONG_LONG_INT
// }	t_format;

// typedef struct s_flags
// {
// 	int zero;
// 	int dot;
// 	int float_precision;
// 	int dash;
// 	int space;
// 	int width;
// 	int u_short;
// 	int u_long;
// 	int u_long_long;
// 	int u_long_double;
// 	int minus;
// 	int plus;
// 	int asterix;
// }				t_flags;

typedef struct s_printf_data
{
	int				count;
	int				error;
	const char		*start;
	const char		*end;
	t_dispatcher_ft	table[256];
	// t_dispatcher_ft sub_tab[256];
	// t_flags		*flags;
}					t_printf_data;

void				ft_write_secure(t_printf_data *data, const char *s, size_t len);
unsigned long int	ft_absolute(int value);


void	dispatcher(t_printf_data *data, va_list arg);


void	ft_print_c(t_printf_data *data, va_list arg);
void	ft_print_s(t_printf_data *data, va_list arg);
void	ft_print_i(t_printf_data *data, va_list arg);
void	ft_print_li(t_printf_data *data, va_list arg);
// void	ft_print_f(t_printf_data *data, va_list arg);
void	ft_print_u(t_printf_data *data, va_list arg);
void	ft_print_lx(t_printf_data *data, va_list arg);
void	ft_print_ux(t_printf_data *data, va_list arg);
void	ft_print_p(t_printf_data *data, va_list arg);
void	ft_print_pc(t_printf_data *data, va_list arg);


void				ft_putc_data(t_printf_data *data, char c);
void				ft_puts_data(t_printf_data *data, const char *s);
void				ft_putuli_data(t_printf_data *data, unsigned long int value,
						unsigned long int base, char *s_base);


#endif
