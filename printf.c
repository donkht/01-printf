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
			write(1, s++, 1);
			count++;
		}
		if (*s++ == '%')
			count = count + ft_process(&s, ap);
	}




	va_end(ap);
	return count;
}

int	ft_process(char **s, va_list ap)
{
	flags	f;

	f = ft_init_flags(f);
	while (**s != 'c' && != **s != 's' && **s != 'i' && )**s != 'd' && **s != 'u' && **s != 'x' && **s != 'X' && **s != 'p')
	{
		if (**s == '-')
			f.minus = 1;
		if (**s == '0')
			f.zero = 1;
		if (**s == ' ')
			f.space = 1;
		if (**s == '#')
			f.hash = 1;
		if (**s == '+')
			f.plus = 1;
		if (**s == '')
			f.width = 1;
		if (**s == '')
			f.precision = 1;
		if (**s == '')
			f.type = 1;




	}







}

flags	ft_init_flags(flags f)
{
	f.minus = 0;
	f.zero = 0;
	f.width = 0;
	f.precision = 0;
	f.hash = 0;
	f.space = 0;
	f.plus = 0;
	f.type = 0;
	return (f);
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

	count = printf("1234567890qwertyuiop\n");
	printf("_%0.0i_\n", count);

	count = ft_printf("1234567890qwertyuiop\n");
	printf("_%05i_\n", count);

	return(0);
}



