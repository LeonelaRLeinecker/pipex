/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:01:18 by leo               #+#    #+#             */
/*   Updated: 2026/01/28 17:04:56 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_path(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
            return (envp[i] + 5);
        i++;
    }
    return (NULL);
}

char    *find_cmd_path(char *cmd, char **envp)
{
    char    **paths;
    //char    *path_from_envp;
    char    *tmp;
    char    *full_path;
    int     i;

    if (!cmd || !envp)
        return (NULL);
    //path_from_envp = get_path(envp);
    paths = ft_split(get_path(envp), ':');
    if (!paths)
        return (NULL);
    i = 0;
    while (paths[i])
    {
        tmp = ft_strjoin(paths[i], "/");
        full_path = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(full_path, X_OK) == 0)
            return (free_split(paths), full_path);
        free(full_path);
        i++;
    }
    return (free_split(paths), NULL);
}