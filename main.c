/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:42:01 by dmonteir          #+#    #+#             */
/*   Updated: 2021/12/27 19:08:29 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"


void free_ptr (char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i++]);
	}
	free(ptr);
}

void free_all (t_data *data)
{
	free_ptr(data->path);
	free_ptr(data->cmd1);
	free_ptr(data->cmd2);
	free(data->path1);
	free(data->path2);
	//free(data->ev);
	//free(data->av);
	//free(data->file_in);
	//free(data->file_out);
	//free(data->fd);
	//free_ptr(data->ev);
	//free_ptr(data->av);
	//free(data->file1);
	//free(data->file2);
}


int	check_path_cmd2(t_data *data)
{
	//Get path of comand 2
	char *temp;
	char *temp1;
	int	i;

	i = 0;
	data->check_cmd = 0;
	while (data->path[++i])
	{
		temp = ft_strjoin(data->path[i], "/");
		temp1 = ft_strjoin(temp, *data->cmd2);
		 if (access(temp1, X_OK) == 0)
		{
			data->path2 = ft_strdup(temp1);
			data->check_cmd = 1;
			break;
		}
		free(temp);
		free(temp1);
	}
	free(temp);
	free(temp1);
	if (data->check_cmd == 0) {
		perror("Command 2 not found!");
		exit(127);
	}
	return (0);
}

int	check_path_cmd1(t_data *data)
{
	//Get path of comand 1
	char *temp;
	char *temp1;
	int	i;

	i = 0;
	data->check_cmd = 0;
	while (data->path[++i])
	{
		temp = ft_strjoin(data->path[i], "/");
		temp1 = ft_strjoin(temp, *data->cmd1);
		 if (!access(temp1, F_OK))
		{
			data->path1 = ft_strdup(temp1);
			data->check_cmd = 1;
			break;
		}
		free(temp);
		free(temp1);
	}
	free(temp);
	free(temp1);
	if (data->check_cmd == 0) {
		perror("Command 1 not found!");
		return (1);
	}
	return (0);
}

/* void	get_cmds(t_data *data, char **argv)
{
	int i;
	//char *teste[2];


	i = 0;
	while (argv[i++])
	{
		if (argv[i] != data->file1 && argv[i] != data->file2)
		{
			data->multi_cmds = argv[i];
			//printf("\n%s\n", data->multi_cmds);
		}
	}
	printf("\n%s\n", data->multi_cmds);
}
 */
char	get_path(t_data *data, char **argv, char **env)
{
	int i;
	char *str;
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
	return(0);
}

void	valid_params(t_data *data, char **argv, char **env)
{
	if (data->ac != 5)
	{
		perror("\nnumber of parameters is incorrect\n");
		exit(EXIT_SUCCESS);
	}
	else {
		get_path(data, argv, env);
	}
}

int main(int argc, char **argv, char **env)
{
	t_data data;
	data.ac = argc;
	data.av = argv;
	data.ev = env;

	valid_params(&data, argv, env);
	return (this_pipex(&data));
}