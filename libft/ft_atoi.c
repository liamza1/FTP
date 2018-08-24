/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:40:19 by lstreak           #+#    #+#             */
/*   Updated: 2017/07/19 07:04:34 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int is_negative;
	int nb;

	is_negative = 0;
	nb = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\v')
			|| (*str == '\n') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == '-')
		is_negative = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if (is_negative == 1)
		return (-nb);
	else
		return (nb);
}
