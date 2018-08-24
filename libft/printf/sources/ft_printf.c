/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:38:38 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:38:39 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	escape_mod2(char *str, int i)
{
	while (str[i] == '%' && str[i + 1] == '%')
		i = i + 2;
	return (i);
}

size_t		ft_nb_arg(char *str)
{
	size_t	nb;

	nb = 0;
	while (*str++)
		if (*str == '%')
			nb++;
	return (nb);
}

static char	**ft_malloc_arg_code(char *str, size_t nb_arg)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*tmp;
	char	**fresh;

	if (!(fresh = malloc(sizeof(char *) * nb_arg + 1)))
		return (NULL);
	i = -1;
	k = 0;
	while (str[++i])
	{
		tmp = ft_strdup("\0");
		i = escape_mod2(str, i);
		if (str[i] == '%' && ft_cm(str, i + 1) == '1' && str[i + 1])
		{
			i++;
			j = 0;
			while (flag_code(str[i + j - 1]) == 0 && str[i + j - 1])
				tmp = ft_strjoin2(tmp, str[i + j++]);
			fresh[k++] = ft_strdup(tmp);
		}
		free(tmp);
	}
	return (fresh);
}

int			ft_printf(char *arg0, ...)
{
	va_list	ap;
	char	**flags;
	int		ret;

	ret = 0;
	if (arg0 == 0)
		ft_putchar('\0');
	flags = ft_malloc_arg_code(arg0, ft_nb_arg(arg0));
	va_start(ap, arg0);
	ret = ft_print_it(arg0, flags, ap, ret);
	va_end(ap);
	free(flags);
	return (ret);
}
