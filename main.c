/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:01:29 by leo               #+#    #+#             */
/*   Updated: 2026/01/27 20:49:34 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    pid_t   pid;

    if (argc != 5)
    {
        write(2, "Wrong argument\n", 15);
        exit(1);
    }
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(1);
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    if (pid == 0)
        child_process(argv, envp, fd);
    else
    {
        waitpid(pid, NULL, 0);
        parent_process(argv, envp, fd);

    }
    return (0);
}