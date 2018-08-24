/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:38:22 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:38:25 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	int		escape_mod(char *str, int i)
{
	int ret;

	ret = 0;
	while (str[i] == '%' && str[i + 1] == '%')
	{
		ret = ft_count_print(1, "ok");
		ft_putchar(str[i]);
		i = i + 2;
	}
	return (i);
}

static	int		print_it3(char *str, int i)
{
	int ret;

	ret = 0;
	i = print_it4(str, i);
	if (str[i + 1] == ' ' && str[i + 2] == '%')
	{
		ft_putchar(str[i + 2]);
		ret = ft_count_print(1, "ok");
		i = i + 2;
	}
	else if ((str[i + 1] == ' ' && str[i] != '%'))
		while (str[i + 1] == ' ')
			i++;
	else if (str[i - 2] != '%' && str[i] == '%' && str[i + 1] == ' '
			&& str[i] + 2 != '%')
		i = i + 2;
	else if (str[i - 2] == '%' && flag_code(str[i - 1]) != 0)
	{
		ret = ft_count_print(1, "ok");
		ft_putchar(str[i]);
		i = i + 2;
	}
	else
		i++;
	return (i);
}

static	int		print_it2(char *str, int i)
{
	int ret;

	ret = 0;
	if (str[i] == '%')
		i = print_it3(str, i);
	else
	{
		ret = ft_count_print(1, "ok");
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

static int		*init_nb(int *n, size_t size)
{
	if (!(n = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	return (n);
}

int				ft_print_it(char *str, char **flags, va_list ap, int ret)
{
	int			*n;
	t_params	*filled;

	n = init_nb(n, 3);
	while (str[n[0]])
	{
		n[0] = escape_mod(str, n[0]);
		if (str[n[0]] == '%' && ft_cm(str, n[0] + 1) == '1' && str[n[0] + 1])
		{
			n[2] = flag_code(flags[n[1]][ft_strlen(flags[n[1]]) - 1]);
			filled = fill_struct_1(flags[n[1]]);
			if (n[2] == 0)
				n[0] = n[0] + spec_case(flags[n[1]++], 0, filled);
			else
			{
				mod_arg1(filled, flags[n[1]], ap, n[2]);
				n[0] = n[0] + ft_strlen(flags[n[1]++]) + 1;
			}
			free(flags[n[1] - 1]);
		}
		else if (str[n[0]])
			n[0] = print_it2(str, n[0]);
	}
	ret = ft_count_print(0, "stop");
	return (ret);
}
