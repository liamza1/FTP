/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:36:48 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:36:50 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	is_al(char c)
{
	int i;

	i = 0;
	if ((c < 124 && c > 96) || (c > 64 && c < 91))
		return (1);
	else
		return (0);
}

static int	spec_case2(t_params *p, size_t len, char *str, int i)
{
	char *pad;

	if (p->zero)
		pad = ft_strdup("0");
	else
		pad = ft_strdup(" ");
	while (str[i] == '.' || str[i] == ' ')
		i++;
	if (p->minus == 1)
		while (str[i] == '-')
			i++;
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (is_al(str[i]) == 1 && str[i] != '-' && ft_isdigit(str[i]) != 0)
		i++;
	if (is_al(str[i]) == 1 && (!(str[i + 1])))
		i++;
	if (is_al(str[i]) == 1 && is_al(str[i + 1]) == 1)
		i++;
	return (i);
}

static char	*spec_case3(t_params *p, char *str3, char *pad, int tmp)
{
	char	c;
	size_t	len;
	char	*str2;

	str2 = ft_strdup("\0");
	len = ft_strlen(str3);
	tmp = p->min_width;
	if (p->min_width != 0 && p->minus == 0 && tmp > len && len == 1)
	{
		while (tmp-- - len > 0)
			str2 = ft_strjoin(pad, str2);
		str3 = ft_strjoin(str2, str3);
	}
	if (p->min_width != 0 && p->minus && tmp > len && len == 1)
		while (tmp-- - len > 0)
			str3 = ft_strjoin(str3, " ");
	if (p->min_width != 0 && p->minus == 1 && tmp > len && len > 1)
	{
		c = str3[0];
		str3 = ft_strsub(str3, 1, len - 1);
		while (tmp-- - 1 > 0)
			str3 = ft_strjoin(" ", str3);
		str3 = ft_strjoin3(c, str3);
	}
	return (str3);
}

static char	*spec_case4(t_params *p, char *str3, char *pad, int tmp)
{
	size_t len;

	len = ft_strlen(str3);
	if (p->min_width != 0 && p->minus == 0 && tmp > len && len > 1)
		while (tmp-- - 1 > 0)
			str3 = ft_strjoin(" ", str3);
	if (p->prec_left)
	{
		str3 = ft_strsub(str3, 1, len - 1);
		while (p->prec_left-- - p->is_precision > 0)
			str3 = ft_strjoin(pad, str3);
	}
	return (str3);
}

int			spec_case(char *str, int i, t_params *p)
{
	int		tmp;
	int		len;
	char	*str3;
	char	*pad;

	len = 0;
	str3 = ft_strdup("\0");
	if (p->zero)
		pad = ft_strdup("0");
	else
		pad = ft_strdup(" ");
	i = spec_case2(p, len, str, i);
	while (str[i] != '\0')
		str3 = ft_strjoin2(str3, str[i++]);
	tmp = p->min_width;
	str3 = spec_case3(p, str3, pad, tmp);
	str3 = spec_case4(p, str3, pad, tmp);
	i = i + 1;
	ft_putstr(str3);
	ft_count_print(ft_strlen(str3), "ok");
	return (i);
}
