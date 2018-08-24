/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:35:01 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:35:03 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_6c(t_params *p, char *str, size_t len, char *flags)
{
	int		tmp;
	char	*pad;

	pad = (flags[0] == '0') ? (ft_strdup("0")) : (ft_strdup(" "));
	tmp = p->min_width - p->space - p->plus;
	if (p->is_width && (flags[0] != '0' || flags[1] != '0') &&
			p->minus == 0 && p->is_neg == 0 && tmp > len && p->plus == 0)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(pad, str);
	else if ((p->is_width && p->minus == 1) && ft_scan_flags(flags, '+') != 1
			&& tmp > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(str, " ");
	else if (p->is_width && (p->is_neg || (p->plus && p->zero == 0)) &&
			tmp > len)
	{
		if (pad[0] == '0')
			str = ft_strsub(str, 1, ft_strlen(str));
		while ((tmp-- - len) > 0)
			str = ft_strjoin(pad, str);
		if (pad[0] == '0')
			str = ft_strjoin("-", str);
	}
	return (str);
}

char	*ft_6b(t_params *p, char *str, char *pad, size_t len)
{
	int tmp;

	tmp = p->min_width - p->plus;
	if (p->plus && p->is_neg == 0 && p->zero && p->is_width
			&& p->min_width > len)
	{
		while ((tmp-- - len) > 0)
			str = ft_strjoin("0", str);
		str = ft_strjoin("+", str);
	}
	else if (p->plus && p->is_neg == 0)
		str = ft_strjoin("+", str);
	if (p->space && p->is_neg == 0 && p->plus == 0 && str[0] != '0')
		str = ft_strjoin(" ", str);
	else if (p->space && p->plus == 0 && p->is_neg == 0)
		str = ft_strjoin("0", str);
	return (str);
}

char	*ft_6d(t_params *p, char *flags, char *str, size_t len)
{
	int tmp;

	tmp = p->prec_right;
	if (p->is_precision && p->prec_right > len && (p->is_neg == 1) && tmp > len)
	{
		str = ft_strsub(str, 1, ft_strlen(str));
		while ((tmp-- + 1 - len) > 0)
			str = ft_strjoin("0", str);
		str = ft_strjoin("-", str);
	}
	if (p->is_precision && p->prec_right > len && (p->is_neg == 0) && tmp > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin("0", str);
	tmp = (len > p->prec_right) ? (len) : (p->prec_right + p->is_neg);
	if (p->is_precision == 1 && (p->prec_left > p->prec_right))
		while ((p->prec_left-- - tmp) > 0)
			str = ft_strjoin(" ", str);
	return (str);
}

char	*ft_6(t_params *p, char *flags, char *str, size_t len)
{
	int		tmp;
	char	*pad;

	if (str[0] == '0' && p->minus == 1)
		str = ft_strdup("0");
	else if (str[0] == '0' && p->j == 0 && p->l == 0 &&
			p->j == 0 && p->z == 0 && p->h == 0 && p->zero == 0)
		str = ft_strdup("\0");
	pad = (flags[0] == '0') ? (ft_strdup("0")) : (ft_strdup(" "));
	str = ft_6b(p, str, pad, len);
	str = ft_6c(p, str, len, flags);
	str = ft_6d(p, flags, str, len);
	free(pad);
	return (str);
}

char	*ft_8(t_params *p, char *flags, char *str, size_t len)
{
	str = ft_6(p, flags, str, len);
	return (str);
}
