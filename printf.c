#include "printf.h"
#include <stdio.h>

int ft_printf(const char *s, ...)
{
	va_list ap;
	int	count;

	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
		{
			write(1, s, 1);
			count++;
		}
		if (*s == '%')
		{




		}
		s++;
	}




	va_end(ap);
	return count;
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*(s + len) != 0)
		len++;
	return (len);
}

int	main(void)
{
	int count;
//	int i = 0xffffff;
	// char *c = "1234567890";

	count = printf("1234567890qwertyuiop");
	printf("_%i\n", count);

	count = ft_printf("1234567890qwertyuiop");
	printf("_%i\n", count);

	return(0);
}



