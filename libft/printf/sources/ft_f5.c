/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:35:27 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:35:29 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_13b(t_params *p, char *pad)
{
	int		i;

	i = 0;
	if (p->prec_left)
		i = ft_write13b(pad, p->prec_left, i);
	else if (p->min_width && p->minus == 0)
		i = ft_write13b(pad, p->min_width, i);
	else if (p->min_width && p->minus)
	{
		i = i + ft_write_null();
		while (p->min_width-- > 1)
			i = i + ft_write_char(' ');
	}
	else if (p->is_precision)
		i = ft_write_null();
	else
		i = ft_write_null();
	ft_count_print(i, "ok");
}

static char	*ft_13c(t_params *p, char *pad, char *str, size_t len)
{
	int tmp;

	tmp = p->min_width;
	if ((p->min_width && p->plus == 0 && p->minus == 0
				&& p->zero == 0) && tmp > len)
		while (--tmp > 0)
			str = ft_strjoin(" ", str);
	tmp = p->min_width;
	if (p->zero && p->minus == 0)
		while (--tmp > 0)
			str = ft_strjoin(pad, str);
	if (p->minus)
		while (--tmp > 0)
			str = ft_strjoin(str, " ");
	if (p->plus && p->minus == 0)
		while (--tmp > 0)
			str = ft_strjoin(" ", str);
	return (str);
}

char		*ft_13(t_params *p, char *flags, char *str, size_t len)
{
	int		tmp;
	char	*pad;

	pad = (flags[0] == '0' || flags[1] == '0' || flags[2] == '0') ?
		(ft_strdup("0")) : (ft_strdup(" "));
	if (str[0] == 0)
		ft_13b(p, pad);
	else
		str = ft_13c(p, pad, str, len);
	free(pad);
	return (str);
}

static char	*ft_14b(t_params *p, char *str, char *pad, size_t len)
{
	int		tmp;

	tmp = p->min_width;
	if ((p->min_width && p->plus == 0 && p->minus == 0
				&& p->zero == 0) && tmp > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(" ", str);
	tmp = p->min_width;
	if ((p->zero && p->minus == 0) && tmp > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(pad, str);
	if (p->minus && tmp > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(str, " ");
	tmp = p->min_width;
	if ((p->plus && p->minus == 0) && tmp > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(" ", str);
	if (ft_strlen(str) == 0)
		ft_count_print(1, "ok");
	return (str);
}

char		*ft_14(t_params *p, char *flags, char *str, size_t len)
{
	int		tmp;
	char	*pad;
	int		len2;

	if (str == 0)
		write(1, "", 1);
	str = ft_getwchar(str);
	len = ft_strlen(str);
	pad = (flags[0] == '0' || flags[1] == '0' || flags[2] == '0') ?
		(ft_strdup("0")) : (ft_strdup(" "));
	str = ft_14b(p, str, pad, len);
	free(pad);
	return (str);
}
