#include "printf.h"
#include <stdio.h>

int ft_printf(const char *s, ...)
{
	va_list ap;

	va_start(ap, s);
				!!!!!!!!!!!!!!!!!!!!!!!!
	write(1, s, ft_strlen(s));
	return 0;
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

	count = printf("s");
	printf("%i\n", count);

	count = ft_printf("s");
	printf("%i\n", count);

	return(0);
}



