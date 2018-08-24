/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:43:29 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:43:33 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_strjoin2(char *s1, char const c)
{
	char			*str;
	unsigned int	nb;
	int				i;

	i = 0;
	if (!s1)
		return (NULL);
	nb = ft_strlen(s1) + 1;
	str = (char *)malloc(sizeof(char) * nb + 1);
	if (!str)
		return (NULL);
	nb = 0;
	while (s1[i])
	{
		*(str + nb) = s1[i++];
		nb++;
	}
	*(str + nb) = c;
	nb++;
	*(str + nb) = '\0';
	free(s1);
	return (str);
}

char			*ft_strjoin3(char const c, char *s1)
{
	char			*str;
	unsigned int	nb;
	int				i;

	i = 0;
	if (!s1)
		return (NULL);
	nb = ft_strlen(s1) + 1;
	str = (char *)malloc(sizeof(char) * nb + 1);
	if (!str)
		return (NULL);
	nb = 0;
	*(str + nb) = c;
	nb++;
	while (s1[i])
	{
		*(str + nb) = s1[i++];
		nb++;
	}
	*(str + nb) = '\0';
	free(s1);
	return (str);
}

size_t			flag_code(char c)
{
	size_t		ret;

	ret = 0;
	(c == 's') ? (ret = 1) : (0);
	(c == 'S') ? (ret = 2) : (0);
	(c == 'x') ? (ret = 3) : (0);
	(c == 'X') ? (ret = 4) : (0);
	(c == 'p') ? (ret = 5) : (0);
	(c == 'd') ? (ret = 6) : (0);
	(c == 'D') ? (ret = 7) : (0);
	(c == 'i') ? (ret = 8) : (0);
	(c == 'o') ? (ret = 9) : (0);
	(c == 'O') ? (ret = 10) : (0);
	(c == 'u') ? (ret = 11) : (0);
	(c == 'U') ? (ret = 12) : (0);
	(c == 'c') ? (ret = 13) : (0);
	(c == 'C') ? (ret = 14) : (0);
	return (ret);
}

static char		*ft_getnbr2(long long nb, long long s, long long v, char *str)
{
	long long	tmp;

	tmp = nb;
	s = 1;
	while (tmp / 10 > 0 && nb != LONG_MIN)
	{
		s = s * 10;
		tmp = tmp / 10;
	}
	while (s > 0 && nb != LONG_MIN)
	{
		v = 0;
		v = nb / s;
		str = ft_strjoin2(str, (v + '0'));
		nb = nb % s;
		s = s / 10;
	}
	return (str);
}

char			*ft_getnbr(long long nb)
{
	long long	tmp;
	long long	value;
	long long	size;
	char		*str;

	str = ft_strdup("\0");
	if (nb == LONG_MIN)
		str = ft_strdup("-9223372036854775808");
	if (nb < 0 && nb != LONG_MIN)
	{
		str = ft_strjoin2(str, '-');
		nb = -nb;
	}
	str = ft_getnbr2(nb, size, value, str);
	return (str);
}
