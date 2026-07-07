#include "libft.h"

void ft_swap(void *a, void *b, size_t size)
{
    t_swap ptr;

	if (a == b || size == 0)
		return ;
	ft_memset(&ptr, 0, sizeof(t_swap));
	ptr.a = (char *)a;
	ptr.b = (char *)b;
	while (ptr.i < size)
	{
		ptr.tmp = ptr.a[ptr.i];
		ptr.a[ptr.i] = ptr.b[ptr.i];
		ptr.b[ptr.i] = ptr.tmp;
		ptr.i++;
	}
}
