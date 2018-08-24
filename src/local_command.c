/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:30:01 by lstreak           #+#    #+#             */
/*   Updated: 2018/08/09 08:30:02 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <unistd.h>

char		**split_entry_l(char *entry)
{
	char	**split;
	char	*tmp;
	int		index;

	index = 0;
	tmp = malloc(ft_strlen(entry) + 1);
	while (*entry)
	{
		while (ft_isspace(*entry))
			entry++;
		while (*entry && ft_isspace(*entry) == 0)
		{
			tmp[index] = *entry;
			index++;
			entry++;
		}
		tmp[index++] = ' ';
	}
	tmp[--index] = '\0';
	split = ft_strsplit(tmp, ' ');
	free(tmp);
	return (split);
}

static void	cd_old_pwd(char **old_pwd)
{
	char	*tmp;

	tmp = *old_pwd;
	*old_pwd = NULL;
	*old_pwd = getcwd(*old_pwd, 0);
	if (tmp)
	{
		if (chdir(tmp))
			printf("error : cant change dir to %s\n", tmp);
		else
			printf("%s\n", tmp);
		free(tmp);
	}
	else
		printf("%s\n", *old_pwd);
}

void		local_cd(char *entry)
{
	char		**cmd;
	static char	*old_pwd = NULL;

	cmd = split_entry_l(entry);
	if (ft_tablen(cmd) > 2)
		printf("lcd: too many arguments\n");
	else if (ft_tablen(cmd) < 2)
		printf("lcd: too few arguments");
	else if (!ft_strcmp(cmd[1], "-"))
		cd_old_pwd(&old_pwd);
	else
	{
		if (old_pwd)
			ft_strdel(&old_pwd);
		old_pwd = getcwd(old_pwd, 0);
		if (chdir(cmd[1]))
			printf("error: cant access dir: %s\n", cmd[1]);
	}
	ft_tabdel(&cmd);
}

void		local_ls(char *entry)
{
	char	**cmd;
	pid_t	father;

	cmd = split_entry_l(entry);
	free(cmd[0]);
	cmd[0] = ft_strdup("/bin/ls");
	father = fork();
	if (father)
		wait(NULL);
	else
		execve(cmd[0], cmd, NULL);
	ft_tabdel(&cmd);
}

void		local_pwd(char *entry)
{
	char	*pwd;
	char	**cmd;

	cmd = split_entry_l(entry);
	if (ft_tablen(cmd) > 1)
		printf("lpwd: too many arguments\n");
	else
	{
		pwd = NULL;
		pwd = getcwd(pwd, 0);
		printf("%s\n", pwd);
		free(pwd);
	}
	ft_tabdel(&cmd);
}
