/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:35:43 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:35:45 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_12(t_params *p, char *flags, char *str, size_t len)
{
	p->l = 1;
	str = ft_11(p, flags, str, len);
	return (str);
}

int		ft_write13b(char *pad, int nbr, int i)
{
	while (nbr-- > 1)
		i = i + ft_write_char(pad[0]);
	i = i + ft_write_null();
	return (i);
}

char	*ft_7(t_params *p, char *flags, char *str, size_t len)
{
	p->l = 1;
	str = ft_6(p, flags, str, len);
	return (str);
}

char	*ft_4(t_params *p, char *flags, char *str, size_t len)
{
	str = str_toupper(ft_3(p, flags, str, len));
	return (str);
}
