#include <client.h>
#include <libft.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

void		exit_error(char *error)
{
	printf("\033[31mError: %s\033[0m\n", error);
	exit (1);
}

static void	usage(char *prog)
{
	printf("\033[31mUsage: %s <127.0.0.1> <port>\033[0m\n", prog);
	exit (1);
}

static int	create_client(char *addr, int port)
{
	int					sock;
	int					ret;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		exit_error("proto resolution");
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	if (sock == -1)
		exit_error("socket creation");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	ret = connect(sock, (const struct sockaddr *)&sin, sizeof(sin));
	if (ret == -1)
		exit_error("connect");
	return (sock);
}

void		clean_exit(char *entry, int sock)
{
	if (entry)
	{
		send_entry(entry, sock);
		free(entry);
	}
	else
		send_entry("quit", sock);
	close(sock);
	exit (0);
}

int			main(int ac, char **av)
{
	char				*ip;
	int					port;
	int					sock;
	struct hostent		*h;

	if (ac != 3)
		usage(av[0]);
	h = gethostbyname(av[1]);
	ip = inet_ntoa(*((struct in_addr *)h->h_addr));
	port = ft_atoi(av[2]);
	sock = create_client(ip, port);
	printf("\033[32mConnection with %s successful\033[0;0m\n", av[1]);
	launch_prompt(sock);
	return (0);
}
