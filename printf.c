#include "printf.h"
#include <stdio.h>

// 4.0
flags	ft_init_flags(void)
{
	flags f;
	f.minus = 0;
	f.zero = 0;
	f.width = 0;
	f.precision = -1;
	f.hash = 0;
	f.space = 0;
	f.plus = 0;
	f.type = 0;
	return (f);
}


//PRINT Char 3.1
int	ft_print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_print_s(char *s, flags f)
{
	int i;

	i = ft_strlen(s);
	if (f.precision > -1 && f.precision <=ft_strlen(s))
		i = f.precision;
	write(1, s, i);
	return (i);
}

//PRINTF 1
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
		{
			s++;
			count = count + ft_process(&s, ap);
			s++;
		}
	}


	va_end(ap);
	return (count);
}

// 4.1
int	ft_parse_digits(const char **ptrs)
{
	int i;
	int digit;

	i = 0;
	digit = 0;
	if (ptrs[0][i] == '.')
		i++;
	while (ptrs[0][i] >= '0' && ptrs[0][i] <= '9')
	{
		digit = digit * 10 + ptrs[0][i] - 48;
		i++;
	}
	*ptrs = *ptrs + i - 1;
	return (digit);
}

//PROCESSING 2
int	ft_process(const char **ptrs, va_list ap)
{
	flags	f;

	f = ft_parse_flags(ptrs);
	if (**ptrs == 'c')
		return(ft_print_c((char)va_arg(ap, int)));
	if (**ptrs == '%')
		return(ft_print_c('%'));
	if (**ptrs == 's')
		return(ft_print_s(va_arg(ap, char *), f));
	// if (**ptrs == 'd' || **ptrs == 'i')
	// 	return(ft_print_id(ap, f));
	// if (**ptrs == 'u')
	// 	return(ft_print_u(ap, f));
	if (**ptrs == 'x')
		return(ft_print_x(va_arg(ap, unsigned int, f));
	// if (**ptrs == 'X')
	// 	return(ft_print_XXX(ap, f));
	// if (**ptrs == 'p')
	// 	return(ft_print_p(ap, f));

	return -1;

}
//PARSER 3.0
flags	ft_parse_flags(const char **ptrs)
{
	const char 	*s;
	flags	f;

	f = ft_init_flags();
	s = *ptrs;
	while (*s != 'c' && *s != 's' && *s != 'i' && *s != 'd' && *s != 'u' && *s != 'x' && *s != 'X' && *s != 'p' && *s != '%')
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
		if (*s == '.')
				f.precision = ft_parse_digits(&s);
		s++;
	}
	*ptrs = s;
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
	char c1 = '!';
	// char c2 = '&';
	int count = 1;
//	int i = 0xffffff;
	// char *c = "1234567890";
	printf("\n\nchar\n");
	count = printf("\t1234567890qwertyuiop_%c_%%_post", c1);
	printf("\tВыведено символов: %i\n", count);
	count = ft_printf("\t1234567890qwertyuiop_%%_%c_post", c1);
	printf("\tВыведено символов: %i\n", count);

	printf("\n\nstring\n");
	count = printf("\t_%.3s_%c_post", "qwertyuiop", '!');
	printf("\tВыведено символов: %i\n", count);
	count = ft_printf("\t_%.3s_%c_post", "qwertyuiop", '!');
	printf("\tВыведено символов: %i\n", count);

	return(0);
}



