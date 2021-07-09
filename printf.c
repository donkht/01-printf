#include "printf.h"
#include <stdio.h>

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

int	ft_print_c(va_start ap, flags f)
{
	char c;

	c = va_arg(ap, char);




}



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
		if (*s == '%')
			count = count + ft_process(&(++s), ap);
	}


	va_end(ap);
	return (count);
}

int	ft_process(char **ptrs, va_list ap)
{
	flags	f;

	f = ft_parse_flags(ptrs);
	if (**ptrs == 'c')
		return(ft_print_c(ap, f));
	// if (**ptrs == 's')
	// 	return(ft_print_s(ap, f));
	// if (**ptrs == 'd' || **ptrs == 'i')
	// 	return(ft_print_id(ap, f));
	// if (**ptrs == 'u')
	// 	return(ft_print_u(ap, f));
	// if (**ptrs == 'x')
	// 	return(ft_print_x(ap, f));
	// if (**ptrs == 'X')
	// 	return(ft_print_XXX(ap, f));
	// if (**ptrs == 'p')
	// 	return(ft_print_p(ap, f));

}

flags	ft_parse_flags(char **ptrs)
{
	char 	*s;
	flags	f;

	f = ft_init_flags(f);
	s = *ptrs;
	while (*s != 'c' && *s != 's' && *s != 'i' && *s != 'd' && *s != 'u' && *s != 'x' && *s != 'X' && *s != 'p')
	{
		if (*s == '-')
			f.minus = 1;
		if (*s == '0')
			f.zero = 1;
		if (*s == ' ')
			f.space = 1;
		if (*s == '#')
			f.hash = 1;
		if (*s == '+')
			f.plus = 1;
		if (*s > '0' && *s <= '9')
			f.width = ft_parse_digits(&s);
		if (*s == '.' && *(s + 1) >= '0' && *(s + 1) <= '9')
			f.precision = ft_parse_digits(&(++s));
		s++;
	}
	*ptrs = s;
	return (f);
}

int	ft_parse_digits(char **ptrs)
{
	int i;
	int digit;

	i = 0;
	digit = 0;
	while (ptrs[0][i] >= '0' && ptrs[0][i] <= '9')
	{
		digit = digit * 10 + ptrs[0][i] - 48;
		i++;
	}
	*ptrs = *ptrs + i - 1;
	return (digit);
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

	count = printf("1234567890qwertyuiop_%0.0i_\n", count);

	count = ft_printf("1234567890qwertyuiop_%05i_\n", count);

	return(0);
}



