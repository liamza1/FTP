/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:34:50 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:34:52 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_3b(t_params *p, size_t len, char *str, char *pad)
{
	int		tmp;

	tmp = p->min_width;
	if (p->is_width && p->minus == 0 && tmp > len)
		while (tmp-- - len > 0)
			str = ft_strjoin(pad, str);
	tmp = p->min_width;
	if (p->minus && p->plus == 0 && tmp > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(str, " ");
	tmp = p->min_width;
	if (p->plus && p->minus && (len < p->min_width) && tmp > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin(str, pad);
	tmp = p->prec_right;
	if (p->is_precision == 1 && p->prec_right > len && tmp > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin("0", str);
	tmp = (len > p->prec_right) ? (len) : (p->prec_right + p->is_neg);
	if (p->is_precision == 1 && (p->prec_left > p->prec_right))
		while ((p->prec_left-- - tmp) > 0)
			str = ft_strjoin(" ", str);
	if (p->diez && p->is_precision && str[0] != '\0')
		str = ft_strjoin("0x", str);
	return (str);
}

char		*ft_3(t_params *p, char *flags, char *str, size_t len)
{
	char	*pad;
	int		tmp;

	if (str[0] == '0' && p->is_precision == 1)
	{
		str = ft_strdup("\0");
		len -= 1;
	}
	if (p->zero && p->minus == 0)
		pad = ft_strdup("0");
	else
		pad = ft_strdup(" ");
	if (p->diez && p->is_precision)
		str = str;
	else if ((p->is_precision && p->diez && p->zero == 0 && str[0] != '\0')
			|| (p->diez && p->zero == 0 && str[0] != '0' && str[0] != '\0'))
		str = ft_strjoin("0x", str);
	(p->diez && p->is_precision == 0) ? (len += 2) : (len = len);
	str = ft_3b(p, len, str, pad);
	if (p->diez && p->is_width && p->zero == 1 && str[0] != '\0')
		str = ft_strjoin("0x", str);
	free(pad);
	return (str);
}

static char	*ft_5b(t_params *p, char *str, size_t len, char *pad)
{
	int		tmp;

	tmp = 0;
	str = ft_strdup("\0");
	tmp = p->prec_right + 1;
	if (p->is_precision == 1 && p->prec_right > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin("0", str);
	tmp = p->min_width;
	if (p->is_width && p->min_width > len && p->minus == 0)
		while (tmp-- - len - 2 > 0)
			str = ft_strjoin(pad, str);
	tmp = p->min_width;
	if (p->is_width && p->min_width > len && p->minus)
		while (tmp-- - len - 2 > 0)
			str = ft_strjoin(str, pad);
	if (p->is_precision == 1)
		str = ft_strjoin("0x", str);
	else if (p->minus == 1 || p->zero)
		str = ft_strjoin("0x0", str);
	else
		str = ft_strjoin(str, "0x0");
	free(pad);
	return (str);
}

static char	*ft_5c(t_params *p, char *flags, char *str, size_t len)
{
	int		tmp;
	char	*pad;

	pad = (flags[0] == '0') ? (ft_strdup("0")) : (ft_strdup(" "));
	tmp = p->prec_right;
	if (p->is_precision == 1 && p->prec_right > len)
		while ((tmp-- - len) > 0)
			str = ft_strjoin("0", str);
	tmp = p->prec_right;
	if (p->is_precision == 1 && (p->prec_left > p->prec_right))
	{
		str = ft_strjoin("0x", str);
		while ((p->prec_left-- - p->prec_right - len) > 0)
			str = ft_strjoin(" ", str);
	}
	else
		str = ft_strjoin("0x", str);
	tmp = p->min_width;
	if (p->is_width && p->min_width && p->plus && len > 0 && p->minus == 0)
		while (tmp-- - 3 > 0)
			str = ft_strjoin(pad, str);
	return (str);
}

char		*ft_5(t_params *p, char *flags, char *str, size_t len)
{
	char	*pad;

	pad = (flags[0] == '0') ? (ft_strdup("0")) : (ft_strdup(" "));
	if (str[0] == '0')
		return (ft_5b(p, str, len, pad));
	else
	{
		str = ft_5c(p, flags, str, len);
		free(pad);
		return (str);
	}
}
