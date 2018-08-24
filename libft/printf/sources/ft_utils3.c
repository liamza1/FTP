/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:43:46 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:43:48 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			print_it4(char *str, int i)
{
	int ret;

	if (str[i] == '%' && str[i + 1] == ' ' && str[i + 2] == ' ')
	{
		ft_putchar(str[i]);
		ret = ft_count_print(1, "ok");
		i++;
	}
	while (str[i] == ' ')
		i++;
	return (i);
}

void		write_count(char pad)
{
	write(1, &pad, 1);
	ft_count_print(1, "ok");
}

void		writen_count(char *str, int len, int len2)
{
	ft_count_print(len, "ok");
	ft_putnwstr(str, len2);
}

char		ft_cm(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (str[i] != ' ' && ft_check(str[i]) == 1)
			return ('1');
		else if (str[i] != ' ' && ft_check(str[i]) == 0)
			return (str[i]);
		else
			i++;
	}
	return ('1');
}

void		init_param_zero(t_params *p)
{
	p->minus = 0;
	p->minus_lg = 0;
	p->plus = 0;
	p->space = 0;
	p->diez = 0;
	p->zero = 0;
	p->is_neg = 0;
	p->h = 0;
	p->l = 0;
	p->j = 0;
	p->z = 0;
	p->is_precision = 0;
	p->prec_left = 0;
	p->prec_right = 0;
	p->is_width = 0;
	p->min_width = 0;
}
