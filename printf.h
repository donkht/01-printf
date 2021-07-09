#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	char	type;
} flags;

int ft_printf(const char *s, ...);
int	ft_strlen(const char *s);
int	ft_process(char **ptrs, va_list ap);
flags	ft_init_flags(flags f);
flags	ft_parse_flags(char **ptrs);

#endif

//Manage any combination of the following flags: ’-0.’ and minimum field width
//with all conversions
//• Manage all the following flags: ’# +’ (yes, one of them is a space)
