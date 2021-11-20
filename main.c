/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:42:01 by dmonteir          #+#    #+#             */
/*   Updated: 2021/11/20 19:10:07 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"


void valid_params(t_data *data)
{
	if (data->ac > 5 || data->ac < 5)
		perror("\nnumber of parameters is incorrect\n");
	else{
		printf("Correct!");
	}
}

int main(int argc, char **argv, char **envp)
{
	t_data data;

	data.ac = argc;
	data.av = argv;
	data.ev = envp;

	ft_bzero(&data, sizeof(t_data));
	valid_params(&data);
	//get_path(data);
	//this_pipe(data);
	return (0);
}