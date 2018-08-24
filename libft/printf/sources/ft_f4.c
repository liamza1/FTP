/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:35:15 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:35:17 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_9b(t_params *p, char *str, size_t len, char *flags)
{
	int		tmp;
	char	*pad;

	pad = (flags[0] == '0' || flags[1] == '0' || flags[2] == '0') ?
		pad = ft_strdup("0") : (ft_strdup(" "));
	tmp = p->min_width - p->space;
	if (p->minus && ft_scan_flags(flags, '+') == 0 && tmp > 0)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(str, " ");
	if (p->diez && (str[0] != '0'))
		str = ft_strjoin("0", str);
	tmp = p->min_width - p->space - p->diez;
	if (p->is_width && p->minus == 0 && tmp > 0)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(pad, str);
	tmp = p->prec_right - p->diez;
	if (p->is_precision == 1 && p->prec_right > len && (p->is_neg == 0))
		while ((tmp-- - len) > 0)
			str = ft_strjoin("0", str);
	tmp = (p->prec_right > len) ?
		(p->prec_left - p->prec_right) : (p->prec_left - len);
	if (p->is_precision == 1 && (p->prec_left > p->prec_right))
		while ((tmp--) > 0)
			str = ft_strjoin(" ", str);
	return (str);
}

char	*ft_9(t_params *p, char *flags, char *str, size_t len)
{
	int		tmp;
	char	*pad;

	tmp = 0;
	if (str[0] == '0' && p->is_precision != 1)
		str = ft_strdup("0");
	if (str[0] == '0' && p->is_precision == 1)
		str = ft_strdup("\0");
	pad = (flags[0] == '0' || flags[1] == '0' || flags[2] == '0') ?
		pad = ft_strdup("0") : (ft_strdup(" "));
	tmp = p->min_width;
	if (p->minus && ft_scan_flags(flags, '+') != 0 && len < tmp)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(str, " ");
	str = ft_9b(p, str, len, flags);
	free(pad);
	return (str);
}

char	*ft_10(t_params *p, char *flags, char *str, size_t len)
{
	p->l = 1;
	str = ft_9(p, flags, str, len);
	return (str);
}

char	*ft_11b(t_params *p, char *flags, char *str, size_t len)
{
	int tmp;

	str = (str[0] == '0' && p->is_precision == 1) ? (ft_strdup("\0")) : (str);
	tmp = p->min_width - p->is_neg;
	if (p->minus && ft_scan_flags(flags, '+') != 0 && tmp > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(str, " ");
	tmp = p->min_width - p->space - p->is_neg;
	if (p->minus && ft_scan_flags(flags, '+') == 0 && tmp > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(str, " ");
	tmp = p->min_width - p->space;
	if (p->is_width && (flags[0] != '0' && flags[1] != '0')
			&& p->minus == 0 && tmp > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(" ", str);
	if ((p->is_width && (flags[0] == '0') || flags[1] == '0')
			&& (p->is_neg == 1) && tmp > len)
	{
		str = ft_strsub(str, 1, ft_strlen(str));
		while ((tmp-- - len) > 0)
			str = ft_strjoin("0", str);
		str = ft_strjoin("-", str);
	}
	return (str);
}

char	*ft_11(t_params *p, char *flags, char *str, size_t len)
{
	int tmp;

	str = ft_11b(p, flags, str, len);
	tmp = p->min_width - p->space;
	if ((p->is_width && (flags[0] == '0' || flags[1] == '0')
				&& (p->is_neg == 0) && tmp > len && p->minus == 0))
		while ((tmp-- - len) > 0)
			str = ft_strjoin("0", str);
	tmp = p->prec_right;
	if (p->is_precision == 1 && p->prec_right > len &&
			(p->is_neg == 1) && tmp > len)
	{
		str = ft_strsub(str, 1, ft_strlen(str));
		while ((tmp-- + 1 - len) > 0)
			str = ft_strjoin("0", str);
		str = ft_strjoin("-", str);
	}
	if (p->is_precision == 1 && p->prec_right > len && (p->is_neg == 0))
		while ((tmp-- - len) > 0)
			str = ft_strjoin("0", str);
	tmp = (len > p->prec_right) ? (len) : (p->prec_right + p->is_neg);
	if (p->is_precision == 1 && (p->prec_left > p->prec_right))
		while ((p->prec_left-- - tmp) > 0)
			str = ft_strjoin(" ", str);
	return (str);
}
