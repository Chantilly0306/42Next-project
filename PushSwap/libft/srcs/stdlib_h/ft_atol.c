#include "libft.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	if (!str || !*str)
		return (LONG_MIN);
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if(str[i] && str[i] != ' ')
		return (LONG_MAX);
	return (result * sign);
}
