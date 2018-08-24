/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:38:06 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:38:07 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_ptab(t_psf **tab)
{
	*tab = (t_psf*)malloc(sizeof(t_psf) * 14);
	(*tab)[0] = &ft_1;
	(*tab)[1] = &ft_2;
	(*tab)[2] = &ft_3;
	(*tab)[3] = &ft_4;
	(*tab)[4] = &ft_5;
	(*tab)[5] = &ft_6;
	(*tab)[6] = &ft_7;
	(*tab)[7] = &ft_8;
	(*tab)[8] = &ft_9;
	(*tab)[9] = &ft_10;
	(*tab)[10] = &ft_11;
	(*tab)[11] = &ft_12;
	(*tab)[12] = &ft_13;
	(*tab)[13] = &ft_14;
}

void	mod_arg1(t_params *p, char *flags, va_list ap, size_t code)
{
	long long	n;
	wchar_t		*tmp;

	n = 0;
	if (!(n = (long long)va_arg(ap, void *)))
		tmp = ft_strdup(n);
	if (code == 6 || code == 8)
		n = ft_conv_di(n, p);
	if (code == 9 || code == 11)
		n = ft_conv_ouxx(n, p);
	if (code == 3 || code == 4)
		n = ft_conv_xx(n, p);
	else if (code == 2 || code == 5 || code == 7 || code == 10 ||
			code == 12 || code == 13 || code == 1 || code == 14)
		n = ft_conv_rem(n, p, code);
	mod_arg2_int(p, flags, n, code);
}

void	mod_arg2_int(t_params *p, char *flags, long long n, size_t code)
{
	char	*tmp;

	tmp = ft_strdup("\0");
	(code == 13 && p->l == 1) ? (code = 14) : (0);
	(code == 1 && p->l) ? (code = 2) : (0);
	(n < 0) ? (p->is_neg = 1) : (0);
	if (code == 6 || code == 8 || code == 7)
		tmp = ft_getnbr(n);
	if (code == 9 || code == 10)
		tmp = ft_ibull(n, 8, 1);
	if (code == 3 || code == 5)
		tmp = ft_ibull(n, 16, 1);
	if (code == 4)
		tmp = ft_ibull(n, 16, 0);
	if (code == 1)
		tmp = ft_strdup(n);
	if (code == 13)
		tmp = ft_putchar_len2(n);
	if (code == 2)
		tmp = n;
	if (code == 12 || code == 11)
		tmp = ft_ibull(n, 10, 1);
	if (code == 14)
		tmp = n;
	mod_arg3_str(p, flags, tmp, code);
}

void	mod_arg3_str(t_params *p, char *flags, char *str, size_t code)
{
	int		len;
	int		tmp;
	int		i;
	t_psf	*p_tab;

	len = 0;
	init_ptab(&p_tab);
	if (code != 2 && code != 14)
		len = ft_strlen(str);
	i = -1;
	while (++i <= 13)
	{
		if (i == code - 1)
		{
			str = (*(p_tab[i]))(p, flags, str, len);
			break ;
		}
	}
	if (code != 2)
	{
		ft_putstr(str);
		ft_count_print(ft_strlen(str), "ok");
	}
	free(p_tab);
}
