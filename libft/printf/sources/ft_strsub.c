/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:42:27 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:42:29 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	start1;
	size_t	i;

	if (s)
	{
		ptr = (char *)malloc(sizeof(*s) * (len + 1));
		if (ptr == NULL)
			return (NULL);
		i = 0;
		start1 = (size_t)start;
		while (len > i && s[start])
		{
			ptr[i] = s[start];
			i++;
			start++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
