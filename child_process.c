/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <lleineck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:10:21 by leo               #+#    #+#             */
/*   Updated: 2026/02/06 20:28:59 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int		file1;
	char	**cmd_args;
	char	*cmd_path;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		error_exit("file1\n");
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO); //file1 --> stdin --> cmd1 --> stdout --> pipe
	close(file1);
	close(fd[0]);
	close(fd[1]);
	cmd_args = ft_split(argv[2], ' ');
	if (!cmd_args)
		error_exit("split: error\n");
	cmd_path = find_cmd_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		free_split(cmd_args);
		error_exit("command not found\n");
	}
	execve(cmd_path, cmd_args, envp);
	free_split(cmd_args);
	free(cmd_path);
	error_exit("execve\n");
}
