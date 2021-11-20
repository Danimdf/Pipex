/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:50:56 by dmonteir          #+#    #+#             */
/*   Updated: 2021/11/20 18:41:12 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*int this_pipex(t_data *data)
{
 	int fd[2];
	int	pid1;

	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
	{
		return 2;
	}
	if (pid1 == 0)
	{
		execve()
	}

}*/