/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ibull.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:36:23 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:36:25 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_ibull(unsigned long long n, int base, int min)
{
	static char		buf[INT_UNS_DIGITS + 2];
	char			*ret;
	char			c;

	c = (min == 1) ? ('a') : ('A');
	if (base < 0)
		return (NULL);
	ret = buf + INT_UNS_DIGITS + 1;
	if (n == 0)
	{
		*--ret = '0';
		return (ret);
	}
	while (n != 0)
	{
		if (base > 10 && n % base >= 10 && n % base <= 15)
			*--ret = c + n % base - 10;
		else
			*--ret = '0' + n % base;
		n /= base;
	}
	return (ret);
}
