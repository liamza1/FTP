/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:34:19 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:34:21 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <wchar.h>
#include <limits.h>
#include <inttypes.h>
#include <locale.h>

typedef struct s_params	t_params;

long long	ft_conv_di(long long nb, t_params *p)
{
	if (p->h == 2)
		return ((signed char)nb);
	else if (p->h == 1)
		return ((short)nb);
	else if (p->l == 2)
		return ((signed long int)nb);
	else if (p->l == 1)
		return ((long)nb);
	else if (p->j)
		return ((intmax_t)nb);
	else if (p->z)
		return ((size_t)nb);
	else
		return ((int)nb);
}

long long	ft_conv_ouxx(long long nb, t_params *p)
{
	(p->h == 2) ? (nb = (unsigned char)nb) : (0);
	(p->h == 1) ? (nb = (unsigned short)nb) : (0);
	(p->l == 2) ? (nb = (unsigned long long)nb) : (0);
	(p->l == 1) ? (nb = (unsigned long)nb) : (0);
	(p->j) ? (nb = (uintmax_t)nb) : (0);
	(p->z) ? (nb = (unsigned long long)nb) : (0);
	(p->j == 0 && p->l == 0 && p->h == 0 && p->z == 0)
		? (nb = (unsigned int)nb) : (0);
	return (nb);
}

long long	ft_conv_xx(long long nb, t_params *p)
{
	if (p->h == 2)
		return ((unsigned char)nb);
	if (p->h == 1)
		return ((unsigned short)nb);
	if (p->l == 2)
		return ((unsigned long long)nb);
	if (p->l == 1)
		return ((unsigned long)nb);
	if (p->j)
		return ((uintmax_t)nb);
	if (p->z)
		return ((size_t)nb);
	return ((unsigned int)nb);
}

long long	ft_conv_rem(long long nb, t_params *p, size_t c)
{
	(c == 13 && p->l == 1) ? (nb = (wchar_t)nb) : (0);
	(c == 1 && p->l == 1) ? (nb = (wchar_t *)nb) : (0);
	(c == 1) ? (nb = (char *)nb) : (0);
	(c == 12) ? (nb = nb) : (0);
	(c == 2) ? (nb = (wchar_t *)nb) : (0);
	(c == 7) ? (nb = (long)nb) : (0);
	(c == 14) ? (nb = (wchar_t)nb) : (0);
	return (nb);
}

int			ft_scan_flags(char *flags, char c)
{
	size_t	i;
	int		tmp;

	tmp = 0;
	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			tmp = tmp + 1;
		i = i + 1;
	}
	return (tmp);
}
