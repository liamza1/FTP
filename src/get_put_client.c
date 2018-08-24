/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_put_client.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:30:30 by lstreak           #+#    #+#             */
/*   Updated: 2018/08/09 08:30:36 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include <libft.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/stat.h>

long		get_file_size(int fd)
{
	struct stat	s;
	long		ret;

	fstat(fd, &s);
	ret = s.st_size;
	return (ret);
}

static int	send_get_command(char *entry, int sock, int fd)
{
	char		*ret;
	long		red;
	long		size;
	char		buf[SIZE_BUF];

	send_entry(entry, sock);
	ret = receive_ret(sock);
	if (!ft_strncmp("OK", ret, 2))
	{
		recv(sock, &size, sizeof(long), 0);
		while (size > 0)
		{
			red = recv(sock, buf, SIZE_BUF, 0);
			if (red == -1)
				return (printf("\033[31mError: sending impossible\033[0m\n"));
			write(fd, buf, red);
			size -= red;
		}
		printf("\033[31mSUCCESS\033[0m	File download successfull\n");
		return (0);
	}
	printf("%s", ret);
	return (1);
}

void		send_get_request(char *entry, int sock)
{
	char		**cmd;
	int			red;
	int			fd;

	cmd = split_entry_l(entry);
	if (ft_tablen(cmd) > 2)
		printf("get: too many arguments\n");
	else if (ft_tablen(cmd) < 2)
		printf("get: too few arguments\n");
	else
	{
		if ((fd = open(cmd[1], O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
			printf("get local: can't create/overwrite %s\n", cmd[1]);
		else
		{
			red = send_get_command(entry, sock, fd);
			close(fd);
			if (red)
				unlink(cmd[1]);
		}
	}
	ft_tabdel(&cmd);
}

static int	send_put_command(char *entry, int sock, int fd, long size)
{
	long		red;
	char		*ret;
	char		buf[SIZE_BUF];

	send_entry(entry, sock);
	ret = receive_ret(sock);
	if (!ft_strncmp("OK", ret, 2))
	{
		send(sock, (const char *)&size, sizeof(long), 0);
		while (size > 0)
		{
			red = read(fd, buf, SIZE_BUF);
			send(sock, buf, red, 0);
			if (red == -1)
				printf("\033[31mError: sending impossible\033[0m\n");
			size -= red;
		}
		printf("\033[31mSUCCESS\033[0m	File upload successfull\n");
		return (0);
	}
	printf("%s", ret);
	return (1);
}

void		send_put_request(char *entry, int sock)
{
	char		**cmd;
	int			red;
	int			fd;
	long		size;

	cmd = split_entry_l(entry);
	if (ft_tablen(cmd) > 2)
		printf("put: too many arguments\n");
	else if (ft_tablen(cmd) < 2)
		printf("put: too few arguments\n");
	else
	{
		if ((fd = open(cmd[1], O_RDONLY)) == -1)
			printf("put local: can't open %s\n", cmd[1]);
		else
		{
			size = get_file_size(fd);
			red = send_put_command(entry, sock, fd, size);
			close(fd);
			if (red)
				unlink(cmd[1]);
		}
	}
	ft_tabdel(&cmd);
}
