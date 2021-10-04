/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tamather <Tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 03:22:28 by Tamather          #+#    #+#             */
/*   Updated: 2021/10/03 20:40:21 by Tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*parse_path(char *path, char *arg)
{
	char	*exe;
	char	*tmp;
	int		i;

	i = 0;
	while (path[i] && path[i] != ':')
		i++;
	tmp = malloc(sizeof(char) * i + 2);
	if (!tmp)
		exit(0);
	ft_bzero(tmp, i + 2);
	i = 0;
	while (*path && *path != ':')
	{
		tmp[i] = *path;
		path++;
		i++;
	}
	tmp[i] = '/';
	exe = ft_strjoin(tmp, arg);
	free(tmp);
	return (exe);
}

char	*get_path(char **envp, char *arg)
{
	int		i;
	char	*path;
	char	*exe;

	i = 0;
	path = NULL;
	while (envp[i] && ft_strncmp("PATH=", envp[i], 5))
		i++;
	if (!envp[i])
		return (arg);
	path = envp[i] + 5;
	while (*path)
	{
		if (*path == ':')
		{
			exe = parse_path(path + 1, arg);
			if (!access(exe, F_OK))
				return (exe);
			free(exe);
		}
		path++;
	}
	return (arg);
}

void	run(char *arg, char **envp)
{
	char	*path;
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(arg, ' ');
	if (!ft_strchr(cmd[0], '/'))
		path = get_path(envp, cmd[0]);
	else
		path = cmd[0];
	execve(path, cmd, envp);
	write(2, "pipex: ", 7);
	write(2, ": command not found\n", 20);
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	exit(127);
}

void	mk_pipe(int fd1, int fd2, char **argv, char **envp)
{
	int		fd[2];
	int		id;

	pipe(fd);
	id = fork();
	if (id == 0)
	{
		dup2(fd1, 0);
		close(fd[0]);
		dup2(fd[1], 1);
		run(argv[2], envp);
	}
	else
	{
		dup2(fd2, 1);
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
		run(argv[3], envp);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	int	file1;
	int	file2;

	if (argc == 5)
	{
		file2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 00664);
		file1 = open(argv[1], O_RDONLY);
		mk_pipe(file1, file2, argv, envp);
	}
	return (0);
}
