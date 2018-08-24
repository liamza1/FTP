/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:44:12 by lstreak           #+#    #+#             */
/*   Updated: 2018/08/07 10:44:13 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <signal.h>
#include <server.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

void	usage(char *prog)
{
	printf("\033[31mUsage: %s <port>\033[0m\n", prog);
	exit(1);
}

void	exit_error(char *error)
{
	printf("\033[31mError: %s\033[0m\n", error);
	exit(1);
}

int		create_server(int port)
{
	int					sock;
	int					ret;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		exit_error("Proto resolution");
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	if (sock == -1)
		exit_error("socket creation");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	ret = bind(sock, (const struct sockaddr *)&sin, sizeof(sin));
	if (ret == -1)
		exit_error("binding");
	ret = listen(sock, 42);
	if (ret)
		exit_error("listen");
	return (sock);
}

void	lauch_dial(int sock)
{
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	pid_t				father;

	signal(SIGCHLD, SIG_IGN);
	while (42)
	{
		cs = accept(sock, (struct sockaddr *)&csin, &cslen);
		if ((father = fork()) == -1)
			exit_error("fork");
		if (father)
			close(cs);
		else
		{
			close(sock);
			while (receive_command(cs))
				;
			close(cs);
			exit(0);
		}
	}
}

int		main(int ac, char **av)
{
	int					port;
	int					sock;

	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	sock = create_server(port);
	lauch_dial(sock);
	return (0);
}
