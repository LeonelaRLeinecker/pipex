/* ************************************************************************** */
/*	                                                                    */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:55:40 by leo               #+#    #+#             */
/*   Updated: 2026/01/27 20:04:18 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"

void	child_process(char **argv, char **envp, int *fd);
void	parent_process(char **argv, char **envp, int *fd);
void	error_exit(const char *message);

//utils
char	*get_path(char **envp);
char	*find_cmd_path(char *cmd, char **envp);
void	free_split(char **split);
void	error_exit(const char *message);

#endif