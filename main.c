/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:42:01 by dmonteir          #+#    #+#             */
/*   Updated: 2021/12/02 20:46:54 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"


char	check_path_cmd1(t_data *data)
{
	//Get path of comand 1
	char *temp;
	char *temp1;
	int	i;

	i = 0;
	//printf("oiii");
	while (data->path[i])
	{
		temp = ft_strjoin(data->path[i], "/");
		temp1 = ft_strjoin(temp, *data->cmd1);

		if (access(temp1, F_OK) == 0)
		{
			data->path1 = ft_strdup(temp1);
			//free(temp);
			//free(temp1);
			//return (data->path1);
			printf ("%s\n", data->path1);
		}
		//free(temp);
		//free(temp1);
		i++;
	}
	//perror("\nInvalids comands. Please check a line command is: ./pipex file1 cmd1 cmd2 file2\n");
	return (0);
}

char	get_path(t_data *data, char **argv, char **env)
{
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
	//printf("%s", str);

	data->path = ft_split(str, ':');
	data->cmd1 = ft_split(argv[2], ' ');
	//printf("%s", argv[2]);
	data->cmd2 = ft_split(argv[3], ' ');
	//printf("%s", argv[3]);

	check_path_cmd1(data);
	return(0);
}

void	valid_params(t_data *data, char **argv, char **env)
{
	if (data->ac != 5)
		perror("\nnumber of parameters is incorrect\n");
	else{
		//printf("\nCorrect!\n");
		get_path(data, argv, env);
	}
	//return (0);
}

int main(int argc, char **argv, char **env)
{
	t_data data;
	data.ac = argc;

	valid_params(&data, argv, env);

	//this_pipe(data);
	return (0);
}