/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:24:23 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/11/18 16:24:26 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd;
	char	*cmd1;
	char	*cmd2;
	char	**envp;
}	t_pipex;

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
void	free_args(char **args);
void	error_exit(const char *message);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*find_path(char *cmd, char **envp);
char	*find_command(char *cmd, char **paths);
int		execute_command(char *cmd, char **envp);
void	setup_files_pipes(char **av, int *infile, int *outfile, int pipefd[2]);
void	setup_execute_child(t_pipex *pipex, int is_first_child);
void	close_all(t_pipex *pipex);

#endif /* PIPEX_H*/
