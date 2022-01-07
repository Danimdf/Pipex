/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_full.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 07:21:51 by dmonteir          #+#    #+#             */
/*   Updated: 2022/01/07 07:23:30 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	dup_path(t_data *data, char *ptr_path, char *temp1)
{
	data->path1 = ft_strdup(temp1);
	data->check_cmd = 1;
	free(ptr_path);
	free(temp1);
}

int	check_path_cmd2(t_data *data)
{
	char	*ptr_path;
	char	*ptr_path_cmd;
	int		i;

	data->path2 = 0;
	i = 0;
	data->check_cmd = 0;
	while (data->path[++i])
	{
		ptr_path = ft_strjoin(data->path[i], "/");
		ptr_path_cmd = ft_strjoin(ptr_path, *data->cmd2);
		if (!access(ptr_path_cmd, X_OK))
		{
			dup_path(data, ptr_path, ptr_path_cmd);
			break ;
		}
		free(ptr_path);
		free(ptr_path_cmd);
	}
	if (data->check_cmd == 0)
	{
		perror("Command 2 not found!");
		exit(127);
	}
	return (0);
}

int	check_path_cmd1(t_data *data)
{
	char	*ptr_path;
	char	*ptr_path_cmd;
	int		i;

	data->path1 = 0;
	i = 0;
	data->check_cmd = 0;
	while (data->path[++i])
	{
		ptr_path = ft_strjoin(data->path[i], "/");
		ptr_path_cmd = ft_strjoin(ptr_path, *data->cmd1);
		if (!access(ptr_path_cmd, F_OK))
		{
			dup_path(data, ptr_path, ptr_path_cmd);
			break ;
		}
		free(ptr_path);
		free(ptr_path_cmd);
	}
	if (data->check_cmd == 0)
	{
		perror("Command 1 not found!");
		return (1);
	}
	return (0);
}

char	get_path(t_data *data, char **argv, char **env)
{
	int		i;
	char	*str;

	data->file1 = argv[1];
	data->file2 = argv[data->ac - 1];
	i = 0;
	str = "";
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			str = ft_strdup(env[i] + 5);
		i++;
	}
	data->path = ft_split(str, ':');
	free(str);
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	check_path_cmd1(data);
	check_path_cmd2(data);
	return (0);
}
