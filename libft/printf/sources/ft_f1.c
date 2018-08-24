/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:34:34 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:34:36 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

typedef struct s_params	t_params;

static char		*ft_1b(t_params *p, char *str, size_t len, char pad)
{
	int			tmp;

	tmp = 0;
	if (str[0] == '\0' && p->prec_left > 0 && p->prec_right > 0)
		len -= 1;
	if (p->is_width && p->minus == 0 && p->min_width)
		while (p->min_width-- - len > 0)
			str = ft_strjoin3(pad, str);
	if (p->minus)
		while ((p->min_width-- - len) > 0)
			str = ft_strjoin2(str, ' ');
	if (p->is_precision)
		str = ft_strsub(str, 0, p->prec_right);
	tmp = (len > p->prec_right) ? (p->prec_right) : (p->prec_right - len);
	if (p->is_precision == 1 && (p->prec_left > p->prec_right))
		while ((p->prec_left-- - tmp) > 0)
			str = ft_strjoin3(' ', str);
	tmp = p->prec_left - len;
	if (p->is_precision == 1 && (p->prec_right > p->prec_left) && tmp > 0)
		while ((tmp--) > 0)
			str = ft_strjoin3(' ', str);
	return (str);
}

char			*ft_1(t_params *p, char *flags, char *str, size_t len)
{
	char		*pad;
	int			tmp;
	int			i;

	tmp = 0;
	i = 0;
	pad = (flags[0] == '0') ? ('0') : (' ');
	if (str == NULL)
		if (p->prec_left)
		{
			str = ft_strdup("\0");
			while (p->prec_left-- > 0)
				str = ft_strjoin3(pad, str);
			return (str);
		}
		else
			return ("(null)");
	else
		return (ft_1b(p, str, len, pad));
}

static char		*ft_2b(t_params *p, size_t len, char *str, char pad)
{
	int			tmp2;
	int			tmp;

	tmp = (p->prec_right < len) ? (p->prec_right) : (len);
	tmp2 = (p->prec_left < p->prec_right) ? (0) :
		(p->prec_left - p->prec_right + p->prec_right % 3);
	if ((p->prec_left) && (p->prec_right <= 2 && p->prec_right != 0))
		tmp2--;
	while (tmp2-- > 0)
		write_count(pad);
	if (p->is_width && p->minus == 0 && p->min_width > len)
		while (p->min_width-- - len > 0)
			write_count(pad);
	if (p->prec_left == 0 && p->prec_right == 0)
		writen_count(str, len, len);
	else if (p->prec_right != 0)
	{
		tmp2 = (ft_strlen(str + 1) % 3 == 0) ? (tmp - tmp % 3 + 1) : (tmp2);
		tmp2 = (ft_strlen(str + 1) % 3 == 1) ? (tmp - tmp % 3) : (tmp2);
		writen_count(str, tmp2, tmp);
	}
	if (p->is_width && p->minus == 1 & p->min_width > len)
		while (p->min_width-- - len > 0)
			write_count(pad);
	return (str);
}

char			*ft_2(t_params *p, char *flags, char *str, size_t len)
{
	char		pad;
	int			tmp;

	tmp = 0;
	pad = (flags[0] == '0' && p->minus == 0) ? ('0') : (' ');
	if (str == NULL)
	{
		ft_putstr("(null)");
		ft_count_print(6, "ok");
	}
	else
	{
		len = ft_wcslen(str);
		str = ft_2b(p, len, str, pad);
	}
	return (str);
}
