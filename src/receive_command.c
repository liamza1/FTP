/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:43:31 by lstreak           #+#    #+#             */
/*   Updated: 2018/08/07 13:43:32 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <server.h>
#include <libft.h>
#include <sys/socket.h>

char		*receive_entry(int sock)
{
	char	*entry;
	long	size;

	recv(sock, &size, sizeof(long), 0);
	entry = ft_strnew(size);
	recv(sock, entry, size, 0);
	return (entry);
}

void		send_ret(char *ret_mes, int sock)
{
	long	ret;
	long	size;

	ret = 0;
	size = ft_strlen(ret_mes);
	send(sock, (const char *)&size, sizeof(long), 0);
	while (size > 0)
	{
		ret = send(sock, ret_mes + ret, size, 0);
		if (ret == -1)
			printf("\033[31mError: sending impossible\033[0m\n");
		size -= ret;
	}
}

static char	*exec_command(char *entry, int sock)
{
	char	*ret;

	ret = NULL;
	if (!ft_strcmp(entry, "quit"))
		return (ret);
	else if (!ft_strncmp(entry, "get", 3))
		exec_get_request(entry, sock);
	else if (!ft_strncmp(entry, "put", 3))
		exec_put_request(entry, sock);
	else if (!ft_strncmp(entry, "cd", 2))
		ret = distant_cd(entry);
	else if (!ft_strncmp(entry, "ls", 2))
		ret = distant_ls(entry);
	else if (!ft_strncmp(entry, "pwd", 3))
		ret = distant_pwd(entry);
	return (ret);
}

int			receive_command(int sock)
{
	char	*entry;
	char	*ret;

	entry = receive_entry(sock);
	ret = exec_command(entry, sock);
	if (ret)
	{
		send_ret(ret, sock);
		free(ret);
		return (1);
	}
	if (!ft_strncmp(entry, "get", 3) || !ft_strncmp(entry, "put", 3))
	{
		free(entry);
		return (1);
	}
	free(entry);
	return (0);
}
