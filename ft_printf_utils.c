#include "ft_printf.h"

int	ft_hex(unsigned long tmp, int base)
{
	int	len;

	len = 0;
	while (tmp >= (unsigned long)base)
	{
		tmp /= base;
		len++;
	}
	return (len);
}
