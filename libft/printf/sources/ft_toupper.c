/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:42:52 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:42:53 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_toupper(int n)
{
	if (n >= 'a' && n <= 'z')
		return (n - 32);
	return (n);
}