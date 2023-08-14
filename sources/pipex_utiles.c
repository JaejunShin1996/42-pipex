/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:22:47 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/14 12:35:06 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file(char *file, int in_out)
{
	int	fd;

	fd = 0;
	if (in_out == 0)
		fd = open(file, O_RDONLY, 0777);
	else if (in_out == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		exit(1);
	return (fd);
}

void	free_container(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

char	*find_path(char *name, char **envp)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		sub = ft_substr(envp[i], 0, j);
		if (ft_strncmp(name, sub, ft_strlen(name)) == 0)
		{
			free(sub);
			return (envp[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**all_path;
	char	**split_cmd;
	char	*one_path;
	char	*exec;

	i = 0;
	all_path = ft_split(find_path("PATH", envp), ':');
	split_cmd = ft_split(cmd, ' ');
	while (all_path[i])
	{
		one_path = ft_strjoin(all_path[i], "/");
		exec = ft_strjoin(one_path, split_cmd[0]);
		free(one_path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_container(split_cmd);
			return (exec);
		}
		free(exec);
		i++;
	}
	free_container(all_path);
	free_container(split_cmd);
	return (cmd);
}
