/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:19:45 by leo               #+#    #+#             */
/*   Updated: 2026/01/28 17:05:02 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    parent_process(char **argv, char **envp, int *fd)
{
    int     file2;
    char    **cmd_args;
    char    *cmd_path;

    file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file2 == -1)
    {
        perror("file2");
        exit(1);
    }
    dup2(fd[0], STDIN_FILENO);
    dup2(file2, STDOUT_FILENO); //pipe --> stdin --> cmd2 --> stdout --> file2//
    close(file2);
    close(fd[0]);
    close(fd[1]);
    cmd_args = ft_split(argv[3], ' ');
    if (!cmd_args)
    {
        perror("split");
        exit(1);
    }
    cmd_path = find_cmd_path(cmd_args[0], envp);
    if (!cmd_path)
    {
        free_split(cmd_args);
        perror("command not found");
        exit(1);
    }
    execve(cmd_path, cmd_args, envp);
    free_split(cmd_args);
    free(cmd_path);
    perror("execve");
    exit(1);
}