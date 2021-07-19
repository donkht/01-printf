#include "ft_printf.h"
#include <stdio.h>

int	ft_print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*(s + len) != 0)
		len++;
	return (len);
}

char	*ft_itoa_base(unsigned int x, int base, int upper_case)
{
	char			*str;
	int				len;
	char			*tab;
	unsigned int	tmp;

	len = 0;
	tab = "0123456789abcdef";
	if (upper_case)
		tab = "0123456789ABCDEF";
	tmp = x;
	len = ft_hex((unsigned long)tmp, base);
	len = len + 1;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = tab[x % base];
		len--;
		x /=base;
	}
	return (str);
}

int	ft_process(const char **ptrs, va_list ap)
{
	if (**ptrs == 'c')
		return (ft_print_c((char)va_arg(ap, int)));
	if (**ptrs == '%')
		return (ft_print_c('%'));
	if (**ptrs == 's')
		return (ft_print_s(va_arg(ap, char *)));
	if (**ptrs == 'd' || **ptrs == 'i')
		return (ft_print_id(va_arg(ap, int)));
	if (**ptrs == 'u')
		return (ft_print_u(va_arg(ap, unsigned int)));
	if (**ptrs == 'x')
		return (ft_print_xX(va_arg(ap, unsigned int), 0));
	if (**ptrs == 'X')
		return (ft_print_xX(va_arg(ap, unsigned int), 1));
	if (**ptrs == 'p')
		return (ft_print_p(va_arg(ap, unsigned long)));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
			count += write(1, s++, 1);
		if (*s == '%')
		{
			s++;
			i = ft_process(&s, ap);
			if (i == -1)
				return (-1);
			count = count + i;
			s++;
		}
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	int	minint = -2147483648;
// 	char c1 = '!';
// 	// char c2 = '&';
// 	int count = 1;
// //	int i = 0xffffff;
// 	// char *c = "1234567890";
// 	printf("\n\nchar\n");
// 	count = printf("\t1234567890qwertyuiop_%c_%%_post", c1);
// 	printf("\tВыведено символов: %i\n", count);
// 	count = ft_printf("\t1234567890qwertyuiop_%%_%c_post", c1);
// 	printf("\tВыведено символов: %i\n", count);

// 	printf("\n\nstring\n");
// 	count = printf("\t_%s_%c_post", NULL, '!');
// 	printf("\tВыведено символов: %i\n", count);
// 	count = ft_printf("\t_%s_%c_post", "qwertyuiop", '!');
// 	printf("\tВыведено символов: %i\n", count);

// 	printf("\n\nhex, HEX\n");
// 	count = printf("_%x_%X_", 456747754, 456747754); //<<<<-------
// 	printf("\tВыведено символов: %i\n", count);
// 	count = ft_printf("_%x_%X_", 456747754, 456747754);
// 	printf("\tВыведено символов: %i\n", count);

// 	printf("\n\nPointer\n");
// 	count = printf("_%p_", NULL); //<<<<-------
// 	printf("\tВыведено символов: %i\n", count);
// 	count = ft_printf("_%p_", NULL);
// 	printf("\tВыведено символов: %i\n", count);

// 	printf("\n\nUnsigned int\n");
// 	count = printf("_%u_", (unsigned int)3000000000); //<<<<-------
// 	printf("\tВыведено символов: %i\n", count);
// 	count = ft_printf("_%u_", (unsigned int)3000000000);
// 	printf("\tВыведено символов: %i\n", count);

// 	printf("\n\nInteger and Digital\n");
// 	count = printf("_%d_%i_", minint, -123); //<<<<-------
// 	printf("\tВыведено символов: %i\n", count);
// 	count = ft_printf("_%d_%i_", minint, -123);
// 	printf("\tВыведено символов: %i\n", count);

// 	printf("\n\n\n");
// 	return(0);
// }
