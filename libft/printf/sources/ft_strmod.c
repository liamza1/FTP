/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:42:12 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:42:14 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_spl(int tmp, int len, char *str, char *pad)
{
	while (tmp-- - len > 0)
		str = ft_strjoin(str, pad);
	return (str);
}
