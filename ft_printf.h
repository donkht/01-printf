#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_print_c(char c);
int		ft_strlen(const char *s);
char	*ft_itoa_base(unsigned int x, int base, int upper_case);
int		ft_printf(const char *s, ...);
int		ft_process(const char **ptrs, va_list ap);
int		ft_print_s(char *s);
int		ft_print_xX(unsigned int ui, int upper_case);
int		ft_print_p(unsigned long ptr);
int		ft_print_u(unsigned int ui);
int		ft_print_id(int id);
int		ft_hex(unsigned long tmp, int base);

#endif
