/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:42:01 by dmonteir          #+#    #+#             */
/*   Updated: 2021/11/20 22:57:35 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

char	get_path(t_data *data)
{
	int i;
	i = 0;
	while (data->ev[i])
	{
		if (ft_strncmp("PATH", *data->ev, 4))
			return (*data->ev[i] + 5);
		i++;
	}
	printf("%d", *data->ev[i] + 5);
	return(0);
}

int	valid_params(t_data *data)
{
	if (data->ac > 5 || data->ac < 5)
		perror("\nnumber of parameters is incorrect\n");
	else{
		printf("Correct!");
	}
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	t_data data;

	data.ac = argc;
	data.av = argv;
	data.ev = envp;

	//ft_bzero(&data, sizeof(t_data));
	valid_params(&data);
	get_path(&data);
	//this_pipe(data);
	return (0);
}