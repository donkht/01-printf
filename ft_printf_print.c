#include "ft_printf.h"

int	ft_print_s(char *s)
{
	int	i;

	if (s == NULL)
		i = write(1, "(null)", 6);
	else
	{
		i = ft_strlen(s);
		write(1, s, i);
	}
	return (i);
}

int	ft_print_xX(unsigned int ui, int upper_case)
{
	char	*str;
	int		i;

	str = ft_itoa_base(ui, 16, upper_case);
	if (str == NULL)
		return (-1);
	i = write(1, str, ft_strlen(str));
	free(str);
	return (i);
}

int	ft_print_p(unsigned long ptr)
{
	char			*str;
	int				len;
	unsigned long	tmp;
	char			*tab;

	len = 0;
	tab = "0123456789abcdef";
	tmp = ptr;
	len = ft_hex(tmp, 16);
	len = len + 1;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = tab[ptr % 16];
		len--;
		ptr /=16;
	}
	len = write(1, "0x", 2) + write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	ft_print_u(unsigned int ui)
{
	char	*str;
	int		i;

	str = ft_itoa_base(ui, 10, 0);
	if (str == NULL)
		return (-1);
	i = write(1, str, ft_strlen(str));
	free(str);
	return (i);
}

int	ft_print_id(int id)
{
	char	*str;
	int		i;

	i = 0;
	if (id < 0)
	{
		write(1, "-", 1);
		i = 1;
		id = -id;
	}
	str = ft_itoa_base(id, 10, 0);
	if (str == NULL)
		return (-1);
	i = i + write(1, str, ft_strlen(str));
	free(str);
	return (i);
}
