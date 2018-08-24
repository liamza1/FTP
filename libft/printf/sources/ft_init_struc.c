/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:36:38 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:36:39 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_params	*fill_struct_1(char *flag)
{
	size_t		i;
	t_params	*params;

	if (!(params = (t_params *)malloc(sizeof(*params))))
		return (NULL);
	init_param_zero(params);
	fill_struct_2(params, flag);
	return (params);
}

void		fill_struct_2(t_params *p, char *flag)
{
	int i;

	i = 0;
	while (i < ft_strlen(flag))
	{
		if (flag[i] != '0' && ft_isdigit(flag[i]) == 1)
			i = fill_struct_3width(p, flag, i);
		(flag[i] == '-') ? (p->minus = 1) : (0);
		(flag[i] == '+') ? (p->plus = 1) : (0);
		(flag[i] == ' ') ? (p->space = 1) : (0);
		(flag[i] == '#') ? (p->diez = 1) : (0);
		(flag[i] == '0') ? (p->zero = 1) : (0);
		(flag[i] == 'h') ? (p->h += 1) : (0);
		(flag[i] == 'l') ? (p->l += 1) : (0);
		(flag[i] == 'j') ? (p->j = 1) : (0);
		(flag[i] == 'z') ? (p->z = 1) : (0);
		if (flag[i] == '.')
			i = fill_struct_3prec(p, flag, i);
		i++;
	}
	(((p->h) % 2) == 0 && (p->h > 2)) ? (p->h = 2) : (0);
	(((p->h) % 2) == 1 && (p->h > 2)) ? (p->h = 1) : (0);
	(((p->l) % 2) == 0 && (p->l > 2)) ? (p->l = 2) : (0);
	(((p->l) % 2) == 1 && (p->l > 2)) ? (p->l = 1) : (0);
}

int			fill_struct_3prec(t_params *p, char *flag, int i)
{
	int		sw;
	char	*cr;
	char	*cl;

	cr = ft_strdup("\0");
	cl = ft_strdup("\0");
	p->is_precision = 1;
	sw = -1;
	while (ft_isdigit(flag[sw + i]) == 1)
		sw--;
	sw++;
	while (ft_isdigit(flag[sw + i]) == 1)
		cl = ft_strjoin2(cl, flag[sw++ + i]);
	sw = 1;
	while (ft_isdigit(flag[sw + i]) == 1)
		cr = ft_strjoin2(cr, flag[sw++ + i]);
	p->prec_left = ft_atoi(cl);
	p->prec_right = ft_atoi(cr);
	i = i + sw;
	p->min_width = 0;
	free(cr);
	free(cl);
	return (i);
}

int			fill_struct_3width(t_params *p, char *flag, int i)
{
	char *w;

	w = ft_strdup("\0");
	p->is_width = 1;
	while (ft_isdigit(flag[i]) == 1)
		w = ft_strjoin2(w, flag[i++]);
	p->min_width = ft_atoi(w);
	free(w);
	return (i);
}

int			ft_check(char c)
{
	int		j;
	char	*array;

	array = ft_strdup("123456789-+#0hljz.sSxXpdDioOuUcC");
	j = 0;
	while (j <= 32)
	{
		if (array[j] == c)
			return (1);
		j++;
	}
	return (0);
}
