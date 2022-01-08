/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 07:09:19 by dmonteir          #+#    #+#             */
/*   Updated: 2022/01/08 20:39:59 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	free_path(t_data *data)
{
	free(data->path1);
	free(data->path2);
}


void	free_all(t_data *data)
{
	free_ptr(data->path);
	free_ptr(data->cmd1);
	free_ptr(data->cmd2);
}

void	exit_free(t_data *data)
{
	free_path(data);
	free_all(data);
	exit(1);
}
