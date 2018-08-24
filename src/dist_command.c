/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:30:51 by lstreak           #+#    #+#             */
/*   Updated: 2018/08/09 08:30:52 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <server.h>
#include <unistd.h>

char		**split_entry(char *entry)
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

static char	*cd_old_pwd(char **old_pwd)
{
	char	*tmp;
	char	*ret;

	tmp = *old_pwd;
	*old_pwd = NULL;
	*old_pwd = getcwd(*old_pwd, 0);
	if (tmp)
	{
		if (chdir(tmp))
			ret = ft_strjoin("\033[31mERROR\033[0m	cd: can't access dir: "
								, tmp);
		else
			ret = ft_strjoin("\033[32mSUCCESS\033[0m	", tmp);
		free(tmp);
	}
	else
		ret = ft_strjoin("\033[32mSUCCESS\033[0m	", *old_pwd);
	return (ret);
}

char		*distant_cd(char *entry)
{
	char		**cmd;
	char		*ret;
	static char	*old_pwd = NULL;

	cmd = split_entry(entry);
	if (ft_tablen(cmd) > 2)
		ret = ft_strdup("\033[31mERROR\033[0m	cd: too many arguments\n");
	else if (ft_tablen(cmd) < 2)
		ret = ft_strdup("\033[31mERROR\033[0m	cd: too few arguments\n");
	else if (!ft_strcmp(cmd[1], "-"))
		ret = cd_old_pwd(&old_pwd);
	else
	{
		if (old_pwd)
			ft_strdel(&old_pwd);
		old_pwd = getcwd(old_pwd, 0);
		if (chdir(cmd[1]))
			ret = ft_strjoin("\033[31mERROR\033[0m	cd: can't access dir: "
								, cmd[1]);
		else
			ret = ft_strdup("\033[32mSUCCESS\033[0m");
	}
	ft_tabdel(&cmd);
	ret = check_cd(ret, old_pwd);
	return (ret);
}

char		*distant_ls(char *entry)
{
	char		**cmd;
	char		*ret;
	char		*tmp;
	int			status;

	cmd = split_entry(entry);
	free(cmd[0]);
	cmd[0] = ft_strdup("/bin/ls");
	tmp = aux_ls(cmd, &status);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		ret = ft_strjoin("\033[31mERROR\033[0m	", tmp);
	else
		ret = ft_strjoin("\033[32mSUCCESS\033[0m\n", tmp);
	free(tmp);
	ft_tabdel(&cmd);
	return (ret);
}

char		*distant_pwd(char *entry)
{
	char	*pwd;
	char	**cmd;
	char	*ret;

	cmd = split_entry(entry);
	if (ft_tablen(cmd) > 1)
		ret = ft_strdup("\033[31mERROR\033[0m	pwd: too many arguments\n");
	else
	{
		pwd = NULL;
		pwd = getcwd(pwd, 0);
		ret = ft_strjoin("\033[32mSUCCESS\033[0m	", pwd);
		free(pwd);
	}
	ft_tabdel(&cmd);
	return (ret);
}
