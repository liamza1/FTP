/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_command_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:30:58 by lstreak           #+#    #+#             */
/*   Updated: 2018/08/09 08:31:00 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <server.h>

static char	*read_result(int fd, int fd_e)
{
	char	*ret;
	char	*tmp;
	char	buf[SIZE_BUF];
	int		red;

	ret = ft_strnew(0);
	while ((red = read(fd, buf, SIZE_BUF - 1)) != 0)
	{
		buf[red] = '\0';
		tmp = ret;
		ret = ft_strjoin(tmp, buf);
		free(tmp);
	}
	while ((red = read(fd_e, buf, SIZE_BUF - 1)) != 0)
	{
		buf[red] = '\0';
		tmp = ret;
		ret = ft_strjoin(tmp, buf);
		free(tmp);
	}
	close(fd);
	close(fd_e);
	return (ret);
}

char		*aux_ls(char **cmd, int *status)
{
	pid_t		father;
	int			fd[2];
	int			fd_e[2];

	pipe(fd);
	pipe(fd_e);
	father = fork();
	if (father)
	{
		close(fd[1]);
		close(fd_e[1]);
		wait(status);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd_e[0]);
		dup2(fd_e[1], 2);
		close(fd_e[1]);
		execve(cmd[0], cmd, NULL);
	}
	return (read_result(fd[0], fd_e[0]));
}

char		*check_cd(char *ret, char *old_pwd)
{
	static char	*verif = NULL;
	char		*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (old_pwd && !verif)
		verif = ft_strdup(old_pwd);
	if (ft_strncmp(cwd, verif, ft_strlen(verif) - 1))
	{
		ret = ft_strjoin_tw("\033[31mERROR\033[0m	"
							, "cd: can't access parent folder of the server: "
							, verif);
		chdir(old_pwd);
	}
	free(cwd);
	return (ret);
}
