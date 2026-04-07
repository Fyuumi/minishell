/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:53:20 by cdenaux           #+#    #+#             */
/*   Updated: 2026/03/04 15:10:38 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n && (s1[i] || s2[i]))
// 	{
// 		if ((unsigned char)s1[i] != (unsigned char)s2[i])
// 			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 		i++;
// 	}
// 	return (0);
// }

// char	*get_path(char **envp)
// {
// 	int	i;

// 	if (!envp)
// 		return (NULL);
// 	i = 0;
// 	while (envp[i])
// 	{
// 		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
// 			return (envp[i] + 5);
// 		i++;
// 	}
// 	return (NULL);
// }

// static char	*join_check_path(char *dir, char *cmd)
// {
// 	char	*full_path;
// 	char	*path_cmd;

// 	full_path = ft_strjoin(dir, "/");
// 	if (!full_path)
// 		return (NULL);
// 	path_cmd = ft_strjoin(full_path, cmd);
// 	free(full_path);
// 	if (!path_cmd)
// 		return (NULL);
// 	if (access(path_cmd, X_OK) == 0)
// 		return (path_cmd);
// 	free(path_cmd);
// 	return (NULL);
// }

// char	*get_cmd_path(char *cmd, char **envp)
// {
// 	char	*path_var;
// 	char	**paths;
// 	size_t	i;
// 	char	*cmd_path;

// 	path_var = get_path(envp);
// 	if (!path_var)
// 		return (NULL);
// 	paths = ft_split(path_var, ':');
// 	if (!paths)
// 		return (NULL);
// 	i = 0;
// 	cmd_path = NULL;
// 	while (paths[i] && !cmd_path)
// 	{
// 		cmd_path = join_check_path(paths[i], cmd);
// 		i++;
// 	}
// 	free_strtab(paths);
// 	return (cmd_path);
// }

