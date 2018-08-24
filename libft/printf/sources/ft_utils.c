/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:43:13 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:43:14 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_write_null(void)
{
	write(1, "", 1);
	return (1);
}

int			ft_write_char(char c)
{
	write(1, &c, 1);
	return (1);
}

char		*ft_putchar_len2(char c)
{
	char	*str;

	if (!(str = malloc((sizeof(char) * 2))))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char		*str_toupper(char *str)
{
	int		i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int			str_isascii(char *str)
{
	int		i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		if (ft_isascii(str[i]) == 0)
			return (0);
		else
			i++;
	}
	return (1);
}
