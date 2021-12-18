/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:42:01 by dmonteir          #+#    #+#             */
/*   Updated: 2021/12/17 23:14:39 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	check_path_cmd2(t_data *data)
{
	//Get path of comand 2
	char *temp;
	char *temp1;
	int	i;

	i = 0;
	data->check_cmd = 0;
	//printf("oiii");
	while (data->path[++i])
	{
		//printf("\n%s\n", data->path[i]);
		temp = ft_strjoin(data->path[i], "/");
		//printf("\n%s\n", temp);
		temp1 = ft_strjoin(temp, *data->cmd2);
		//printf("\n%s\n", temp1);
		//printf("\n%s\n", temp1);
		 if (access(temp1, X_OK) == 0)
		{
			data->path2 = ft_strdup(temp1);

			data->check_cmd = 1;

			//printf("\n%s\n", data->path2);
			break;
		}
		free(temp);
		free(temp1);
	}
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
	//printf("oiii");
	while (data->path[++i])
	{
		//printf("\n%s\n", data->path[i]);
		temp = ft_strjoin(data->path[i], "/");
		//printf("\n%s\n", temp);
		//data->cmd1 = ft_split(*data->cmd1, " ");
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
	if (data->check_cmd == 0) {
		perror("Command 1 not found!");
		return (1);
	}//perror("\nInvalids comands. Please check a line command is: ./pipex file1 cmd1 cmd2 file2\n");
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
	data->cmd1 = ft_split(argv[2], ' ');


	data->cmd2 = ft_split(argv[3], ' ');/*
	dprintf(2, "\n$$$%s$$$\n", argv[2]);
	printf("\n$$$%s$$$\n", data->cmd1[2]); */

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