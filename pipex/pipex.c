/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:24:08 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/11/18 16:24:14 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup_files_pipes(char **av, int *infile, int *outfile, int pipefd[2])
{
	*infile = open(av[1], O_RDONLY, 0777);
	if (*infile < 0)
	{
		if (errno == ENOENT)
		{
			perror(av[1]);
			exit(127);
		}
		else if (errno == EACCES)
		{
			perror(av[1]);
			exit(126);
		}
	}
	*outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (*outfile < 0)
		error_exit("Failed to open output file");
	if (pipe(pipefd) == -1)
		error_exit("Failed to create a pipe");
	return ;
}

void	setup_execute_child(t_pipex *pipex, int is_first_child)
{
	if (is_first_child == 1)
	{
		pipex->in_fd = pipex->infile;
		pipex->out_fd = pipex->pipefd[1];
		pipex->cmd = pipex->cmd1;
		close(pipex->pipefd[0]);
	}
	else
	{
		pipex->in_fd = pipex->pipefd[0];
		pipex->out_fd = pipex->outfile;
		pipex->cmd = pipex->cmd2;
		close(pipex->pipefd[1]);
	}
	if (dup2(pipex->in_fd, STDIN_FILENO) == -1
		|| dup2(pipex->out_fd, STDOUT_FILENO) == -1)
		error_exit("Failed to duplicate file descriptors");
	close(pipex->in_fd);
	close(pipex->out_fd);
	execute_command(pipex->cmd, pipex->envp);
	return ;
}

void	close_all(t_pipex *pipex)
{
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	close(pipex->infile);
	close(pipex->outfile);
	return ;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		error_exit("Not right amount of arguments\n");
	setup_files_pipes(av, &pipex.infile, &pipex.outfile, pipex.pipefd);
	pipex.cmd1 = av[2];
	pipex.cmd2 = av[3];
	pipex.envp = envp;
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		error_exit("Failed to fork");
	if (pipex.pid1 == 0)
		setup_execute_child(&pipex, 1);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		error_exit("Failed to fork");
	if (pipex.pid2 == 0)
		setup_execute_child(&pipex, 0);
	close_all(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}
