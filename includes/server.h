/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:46:01 by lstreak           #+#    #+#             */
/*   Updated: 2018/08/06 10:46:02 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define SIZE_BUF	1024

int		receive_command(int sock);
void	exec_get_request(char *entry, int sock);
void	exec_put_request(char *entry, int sock);
void	send_ret(char *ret_mes, int sock);
char	*receive_entry(int sock);
char	*distant_cd(char *entry);
char	*distant_ls(char *entry);
char	*distant_pwd(char *entry);
char	*aux_ls(char **cmd, int *status);
char	*check_cd(char *ret, char *old_pwd);
char	**split_entry(char *entry);

#endif
