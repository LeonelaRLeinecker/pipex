/* ************************************************************************** */
/*                                                                            */
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



void    child_process(char **argv, char **envp, int *fd);
void    parent_process(char **argv, char **envp, int *fd);

//utils
char *get_path(char **envp);
char    *find_cmd_path(char *cmd, char **envp);


//libft
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**create_memory(int size);
char	**free_split(char **result);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);


#endif

