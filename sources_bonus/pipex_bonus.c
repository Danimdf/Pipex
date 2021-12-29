/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:42:01 by dmonteir          #+#    #+#             */
/*   Updated: 2021/12/29 19:20:07 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"
/*

void free_ptr (char **ptr) {
	int i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void free_path(t_data *data) {
	free(data->path1);
	free(data->path2);
}

void free_all (t_data *data) {
	free_ptr(data->path);
	free_ptr(data->cmd1);
	free_ptr(data->cmd2);
}
 */
/*
int	check_path_cmd2(t_data *data) {
	//Get path of comand 2
	char *temp;
	char *temp1;
	int	i;

	data->path2 = 0;
	i = 0;
	data->check_cmd = 0;
	while (data->path[++i]) {
		temp = ft_strjoin(data->path[i], "/");
		temp1 = ft_strjoin(temp, *data->cmd2);
		printf("%s\n", temp1);
		if (!access(temp1, X_OK))
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
		//free_ptr(data->path);
		//free_ptr(data->cmd2);
		//free(data->path2);
		exit(127);
	}
	return (0);
}

int	check_path_cmd1(t_data *data) {
	//Get path of comand 1
	char *ptr_path;
	char *temp1;
	int	i;

	data->path1 = 0;
	i = 0;
	data->check_cmd = 0;
	while (data->path[++i]) {
		ptr_path = ft_strjoin(data->path[i], "/");
		temp1 = ft_strjoin(ptr_path, *data->cmd1);
		 if (!access(temp1, F_OK))
		{
			data->path1 = ft_strdup(temp1);
			data->check_cmd = 1;
			break;
		}
		free(ptr_path);
		free(temp1);
	}
	free(ptr_path);
	free(temp1);
	if (data->check_cmd == 0) {
		perror("Command 1 not found!");
		return (1);
	}
	return (0);
} */
/*
void	get_cmds(t_data *data, char **argv)
{
	int i;
	char *temp;
	//char *teste[2];

	//printf("oiii\n");
	i = 0;
	while (argv[i++])
	{
		if (argv[i] != data->file1 && argv[i] != data->file2)
		{
			temp = (argv[i]);
			data->multi_cmds = ft_strdup(temp);
			printf("\n%s\n", *data->multi_cmds);
		}
	}
	//printf("\n%s\n", *data->multi_cmds);
} */

char	get_path(t_data *data, char **env) {
	int i;
	char *str;


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
	//get_cmds(data, argv);
	//data->cmd1 = ft_split(argv[2], ' ');
	//data->cmd2 = ft_split(argv[3], ' ');

	//check_path_cmd1(data);
	//check_path_cmd2(data);
	return(0);
}

void	valid_params(t_data *data, char **env) {
	if (data->ac < 5) {
		perror("\nnumber of parameters is incorrect\n");
		exit(EXIT_SUCCESS);
	}
	else {
		get_path(data, env);
	}
}

int init_pipex(t_data *data, int argc, char **argv, char **env) {
	int i;

	data->ac = argc;
	data->av = argv;
	data->ev = env;
	data->file1 = argv[1];
	data->file2 = argv[data->ac - 1];
	data->count_cmds = argc - 3;
	data->multi_cmds = malloc(data->count_cmds * sizeof(char *));
	i = 0;

	//printf("\noi");

	while(i < data->count_cmds)
	{
		//printf("oi");
		data->multi_cmds[i] = malloc(ft_strlen(argv[i + 2]) * sizeof(char));
		data->multi_cmds[i] = argv[i + 2];
		i++;
	}
	printf("\n%s\n", data->multi_cmds[3]);

	return (0);
}

int main(int argc, char **argv, char **env) {
	t_data data;

	printf("%d", argc);
	init_pipex(&data, argc, argv, env);
	valid_params(&data, env);
	//return (this_pipex(&data));
}