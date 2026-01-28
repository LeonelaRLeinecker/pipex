/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:10:21 by leo               #+#    #+#             */
/*   Updated: 2026/01/28 17:04:59 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    child_process(char **argv, char **envp, int *fd)
{
    int     file1;
    char    **cmd_args;
    char    *cmd_path;

    file1 = open(argv[1], O_RDONLY);
    if (file1 == -1)
    {
        perror("file1");
        exit(1);
    }
    dup2(file1, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO); //file1 --> stdin --> cmd1 --> stdout --> pipe//
    close(file1);
    close(fd[0]);
    close(fd[1]);
    // parseo argumentos
    cmd_args = ft_split(argv[2], ' ');
    if (!cmd_args)
    {
        perror("split");
        exit(1);
    }
    // find path
    cmd_path = find_cmd_path(cmd_args[0], envp);
    if (!cmd_path)
    {
        free_split(cmd_args);
        perror("command not found");
        exit(1);
    }
    // exit code execve crear execute?

    execve(cmd_path, cmd_args, envp);
    free_split(cmd_args);
    free(cmd_path);
    perror("execve");
    exit(1);

}
