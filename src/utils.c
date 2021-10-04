/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tamather <Tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:22:18 by Tamather          #+#    #+#             */
/*   Updated: 2021/10/04 17:00:29 by Tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*parse_path(char *path, char *arg)
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
		if (path == envp[i] + 5 || *path == ':')
		{
			exe = parse_path(path + !(path == envp[i] + 5), arg);
			if (!access(exe, F_OK))
				return (exe);
			free(exe);
		}
		path++;
	}
	return (arg);
}

void	error(char *name, char *err)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
}
