/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_put_server.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:30:17 by lstreak           #+#    #+#             */
/*   Updated: 2018/08/09 08:30:19 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include <server.h>
#include <libft.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/stat.h>

long		get_file_siza(int fd)
{
	struct stat s;
	long		ret;

	fstat(fd, &s);
	ret = s.st_size;
	return (ret);
}

static void	exec_get_command(int sock, int fd, long size)
{
	long	ret;
	char	buf[SIZE_BUF];

	send(sock, (const char *)&size, sizeof(long), 0);
	while (size > 0)
	{
		ret = read(fd, buf, SIZE_BUF);
		send(sock, buf, ret, 0);
		if (ret == -1)
			printf("\033[31mError: sending impossibel\033[0m\n");
		size -= ret;
	}
}

void		exec_get_request(char *entry, int sock)
{
	char		**cmd;
	char		*ret;
	int			fd;
	long		size;

	cmd = split_entry(entry);
	if ((fd = open(cmd[1], O_RDONLY)) == -1)
	{
		ret = ft_strjoin_tw("\033[31mERROR\033[0m	get server: can't open "
						, cmd[1], "\n");
		send_ret(ret, sock);
	}
	else
	{
		ret = ft_strdup("OK");
		send_ret(ret, sock);
		size = get_file_siza(fd);
		exec_get_command(sock, fd, size);
		close(fd);
	}
	free(ret);
	ft_tabdel(&cmd);
}

static void	exec_put_command(int sock, int fd)
{
	long	red;
	long	size;
	char	buf[SIZE_BUF];

	recv(sock, &size, sizeof(long), 0);
	while (size > 0)
	{
		red = recv(sock, buf, SIZE_BUF, 0);
		if (red == -1)
			printf("\033[31mError: receiving impossible\033[0m\n");
		write(fd, buf, red);
		size -= red;
	}
}

void		exec_put_request(char *entry, int sock)
{
	char	**cmd;
	char	*ret;
	int		fd;

	cmd = split_entry(entry);
	if ((fd = open(cmd[1], O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
	{
		ret = ft_strjoin_tw("\033[31mERROR\033[0m	get server: can't create "
						, cmd[1], "\n");
		send_ret(ret, sock);
	}
	else
	{
		ret = ft_strdup("OK");
		send_ret(ret, sock);
		exec_put_command(sock, fd);
		close(fd);
	}
	free(ret);
	ft_tabdel(&cmd);
}
