/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:45:51 by lstreak           #+#    #+#             */
/*   Updated: 2018/08/06 10:45:53 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define SIZE_BUF	1024

void	launch_prompt(int sock);
void	exit_error(char *error);
void	local_cd(char *entry);
void	local_ls(char *entry);
void	local_pwd(char *entry);
void	send_get_request(char *entry, int sock);
void	send_put_request(char *entry, int sock);
void	send_command(char *entry, int sock);
void	clean_exit(char *entry, int sock);
int		send_entry(char *entry, int sock);
char	*receive_ret(int sock);
char	**split_entry_l(char *entry);

#endif
