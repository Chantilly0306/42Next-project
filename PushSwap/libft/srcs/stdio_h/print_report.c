#include "push_swap.h"
#include <unistd.h>
#include <stdarg.h>

static int ft_print_str(char *str)
{
    int i;

    if (!str)
        return (write(2, "(null)", 6));
    i = 0;
    while (str[i])
        write(2, &str[i++], 1);
    return (i);
}

static int ft_print_nbr(int nbr)
{
    int     len;
    char    c;

    if (nbr == -2147483648)
        return (write(2, "-2147483648", 11));
    len = 0;
    if (nbr < 0)
    {
        len += write(2, "-", 1);
        nbr = -nbr;
    }
    if (nbr >= 10)
        len += ft_print_nbr(nbr / 10);
    c = '0' + nbr % 10;
    len += write(2, &c, 1);
    return (len);
}

static int ft_print_float(double num)
{
    int len;
    int integral;
    int fractional;

    len = 0;
    integral = (int)num;
    fractional = (int)((num - integral) * 100 + 0.5);
    len += ft_print_nbr(integral);
    len += write(2, ".", 1);
    if (fractional < 10)
        len += write(2, "0", 1);
    len += ft_print_nbr(fractional);
    return (len);
}

static int parse_conversion(char format, va_list *args)
{
    int len;

    len = 0;
    if (format == 's')
        len += ft_print_str(va_arg(*args, char *));
    else if (format == 'd' || format == 'i')
        len += ft_print_nbr(va_arg(*args, int));
    else if (format == 'f')
        len += ft_print_float(va_arg(*args, double));
    else if (format == '%')
        len += write(2, "%", 1);
    return (len);
}

int print_report(const char *fm, ...)
{
    va_list args;
    int i;
    int total_len;

    if (!fm)
        return (-1);
    i = 0;
    total_len = 0;
    va_start(args, fm);
    while (fm[i])
    {
        if (fm[i] == '%')
        {
            i++;
            while (fm[i] == '.' || (fm[i] >= '0' && fm[i] <= '9'))
                i++;
            if (fm[i] == 's' || fm[i] == 'd' || fm[i] == 'f' || fm[i] == '%')
                total_len += parse_conversion(fm[i], &args);
        }
        else
            total_len += write(2, &fm[i], 1);
        i++;
    }
    return (va_end(args), total_len);
}