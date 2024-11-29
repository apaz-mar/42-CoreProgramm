/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:29:04 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/11/25 16:29:06 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(const char *message)
{
	perror(message);
	exit(1);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
	return ;
}

char	*find_path_command(char *cmd, char **envp)
{
	int		i;
	char	*cmd_path;
	char	*path_env;
	char	**paths;

	path_env = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	cmd_path = find_command(cmd, paths);
	free_args(paths);
	return (cmd_path);
}

char	*find_command(char *cmd, char **paths)
{
	int		i;
	char	*cmd_path;
	char	*full_cmd;

	i = 0;
	while (paths[i] != NULL)
	{
		cmd_path = ft_strjoin(paths[i], "/");
		if (!cmd_path)
			return (NULL);
		full_cmd = ft_strjoin(cmd_path, cmd);
		free(cmd_path);
		if (!full_cmd)
			return (NULL);
		if (access(full_cmd, X_OK) == 0)
			return (full_cmd);
		free(full_cmd);
		i++;
	}
	return (NULL);
}

int	execute_command(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		free_args(args);
		error_exit("Failed to parse command");
	}
	cmd_path = find_path_command(args[0], envp);
	if (!cmd_path)
	{
		perror("Command not found");
		free_args(args);
		exit(127);
	}
	if (execve(cmd_path, args, envp) == -1)
	{
		free_args(args);
		free(cmd_path);
		error_exit("execve failed");
	}
	free_args(args);
	free(cmd_path);
	return (0);
}
