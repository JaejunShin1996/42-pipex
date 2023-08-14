/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:10:33 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/14 12:29:30 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute(char *cmd, char **envp)
{
	char	**split_cmd;
	char	*path;
	int		result;

	split_cmd = ft_split(cmd, ' ');
	path = get_path(split_cmd[0], envp);
	result = execve(path, split_cmd, envp);
	if (result == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(split_cmd[0], 2);
		free_container(split_cmd);
		exit(1);
	}
}

void	child(char **argv, int *p_fd, char **envp)
{
	int	fd;

	fd = open_file(argv[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	execute(argv[2], envp);
}

void	parent(char **argv, int *p_fd, char **envp)
{
	int	fd;

	fd = open_file(argv[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		p_fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putendl_fd("./pipex infile cmd1 cmd2 outfile", 2);
		exit(1);
	}
	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		child(argv, p_fd, envp);
	parent(argv, p_fd, envp);
	return (0);
}
