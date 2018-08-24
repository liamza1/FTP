/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:43:11 by lstreak           #+#    #+#             */
/*   Updated: 2018/08/07 13:43:12 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <client.h>
#include <libft.h>
#include <sys/socket.h>

int			send_entry(char *entry, int sock)
{
	long	ret;
	long	size;

	ret = 0;
	size = ft_strlen(entry);
	send(sock, (const char *)&size, sizeof(long), 0);
	while ((ret += send(sock, entry + ret, size, 0)) != size)
	{
		if (ret == -1)
		{
			printf("\033[31mError: sending impossible\033[0m\n");
			return (1);
		}
	}
	return (0);
}

char		*receive_ret(int sock)
{
	char	*ret_ms;
	long	size;

	recv(sock, &size, sizeof(long), 0);
	ret_ms = ft_strnew(size);
	recv(sock, ret_ms, size, 0);
	return (ret_ms);
}

void		send_command(char *entry, int sock)
{
	char	*ret;

	if (!send_entry(entry, sock))
	{
		ret = receive_ret(sock);
		printf("%s\n", ret);
		free(ret);
	}
}
