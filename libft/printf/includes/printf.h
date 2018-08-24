/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:33:30 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:33:32 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define INT_DIGITS 19
# define INT_UNS_DIGITS 21

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <locale.h>
# include <limits.h>
# include <wchar.h>
# include <inttypes.h>

typedef struct s_params	t_params;
typedef char *(*t_psf)(struct s_params *, char *, char *, size_t);

struct		s_params
{
	int		valid;
	int		minus;
	int		minus_lg;
	int		plus;
	int		space;
	int		diez;
	int		zero;
	int		is_neg;
	int		h;
	int		l;
	int		j;
	int		z;
	int		is_precision;
	int		prec_left;
	int		prec_right;
	int		is_width;
	int		min_width;
};

int			print_it4(char *str, int i);
void		init_ptab(t_psf **tab);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strjoin2(char *s1, char const c);
char		*ft_strjoin3(char const c, char *s1);
size_t		flag_code(char c);
size_t		ft_nb_arg(char *str);
int			ft_print_it(char *str, char **flags, va_list ap, int ret);
int			ft_printf(char *arg0, ...);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dst, const char *src);
void		ft_putchar(char c);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		init_param_zero(t_params *p);
t_params	*fill_struct_1(char *flag);
int			ft_write_null(void);
int			ft_write_char(char c);
int			str_isascii(char *str);
void		fill_struct_2(t_params *p, char *flag);
int			fill_struct_3prec(t_params *p, char *flag, int i);
int			fill_struct_3width(t_params *p, char *flag, int i);
long long	ft_conv_di(long long nb, t_params *p);
long long	ft_conv_rem(long long nb, t_params *p, size_t c);
long long	ft_conv_ouxx(long long nb, t_params *p);
long long	ft_conv_xx(long long nb, t_params *p);
void		mod_arg1(t_params *p, char *flags, va_list ap, size_t code);
void		mod_arg2_int(t_params *p, char *flags, long long n, size_t code);
void		mod_arg3_str(t_params *p, char *flags, char *str, size_t code);
char		*ft_ibull(unsigned long long n, int base, int min);
int			ft_toupper(int n);
int			spec_case(char *str, int i, t_params *p);
int			ft_tolower(int n);
int			ft_isascii(int n);
char		*ft_getnbr(long long nb);
char		*ft_putchar_len2(char c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
long long	ft_count_print(int fill_me, char *c);
int			ft_scan_flags(char *flags, char c);
char		*ft_1(t_params *p, char *flags, char *str, size_t len);
char		*ft_2(t_params *p, char *flags, char *str, size_t len);
char		*ft_3(t_params *p, char *flags, char *str, size_t len);
char		*ft_4(t_params *p, char *flags, char *str, size_t len);
char		*ft_5(t_params *p, char *flags, char *str, size_t len);
char		*ft_6(t_params *p, char *flags, char *str, size_t len);
char		*ft_7(t_params *p, char *flags, char *str, size_t len);
char		*ft_8(t_params *p, char *flags, char *str, size_t len);
char		*ft_9(t_params *p, char *flags, char *str, size_t len);
char		*ft_10(t_params *p, char *flags, char *str, size_t len);
char		*ft_11(t_params *p, char *flags, char *str, size_t len);
char		*ft_12(t_params *p, char *flags, char *str, size_t len);
char		*ft_13(t_params *p, char *flags, char *str, size_t len);
char		*ft_14(t_params *p, char *flags, char *str, size_t len);
char		*str_toupper(char *str);
void		ft_putwchar_fd(wchar_t chr, int fd);
void		ft_putnwstr(const wchar_t *str, size_t len);
char		*ft_getwchar(wchar_t chr);
size_t		ft_cslen(wchar_t wc);
size_t		ft_wcslen(wchar_t *str);
char		ft_cm(char *str, int i);
void		write_count(char pad);
void		writen_count(char *str, int len, int len2);
int			ft_write13b(char *pad, int nbr, int i);
#endif
