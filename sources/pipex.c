/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:42:01 by dmonteir          #+#    #+#             */
/*   Updated: 2022/01/07 18:03:03 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	valid_params(t_data *data, char **argv, char **env)
{
	if (data->ac != 5)
	{
		perror("\nnumber of parameters is incorrect\n");
		exit_free(data);
	}
	else
		get_path(data, argv, env);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	data.ac = argc;
	data.av = argv;
	data.ev = env;
	valid_params(&data, argv, env);
	return (this_pipex(&data));
}
