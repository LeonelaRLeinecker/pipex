/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <lleineck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:01:29 by leo               #+#    #+#             */
/*   Updated: 2026/02/06 20:29:03 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		error_exit("Wrong argument\n");
	if (pipe(fd) == -1)
		error_exit("pipe: error\n");
	pid = fork();
	if (pid == -1)
		error_exit("fork: error\n");
	if (pid == 0)
		child_process(argv, envp, fd);
	else
	{
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, fd);
	}
	return (0);
}
