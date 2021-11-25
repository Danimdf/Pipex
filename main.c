/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:42:01 by dmonteir          #+#    #+#             */
/*   Updated: 2021/11/24 20:58:08 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

/*char	get_path(t_data *data)
{
	int i;
	i = 0;
	while (data->ev[i])
	{
		if (ft_strncmp("PATH=", data->ev[i], 5))
			return (*data->ev[i] + 5);
		i++;
	}
	//printf("%s", *data->ev);
	return(0);
}*/

void	valid_params(t_data *data)
{
	if (data->ac != 5)
		perror("\nnumber of parameters is incorrect\n");
	else{
		printf("\nCorrect!\n");
		//get_path(data);
	}
	//return (0);
}

int main(int argc, char *argv[], char *env[])
{
	t_data data;
	int i;
	data.ac = argc;
	data.av = *argv;
	i = -1;
	while (env[++i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	//ft_bzero(&data, sizeof(t_data));
	valid_params(&data);

	//this_pipe(data);
	return (0);
}