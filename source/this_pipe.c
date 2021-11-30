/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:50:56 by dmonteir          #+#    #+#             */
/*   Updated: 2021/11/27 19:01:48 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
/* input = ./pipex infile "grep a1" "wc -w" outfile
is the same =  “< infile grep a1 | wc -w > outfile” */

/*int	parent_execution(t_data *data)
{

}*/

/*void	child_execution(int fd)
{
	dup2(fd[1]), STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
}


int this_pipex(t_data *data)
{
 	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("Error");
	}
	if (pid1 == 0)
	{
		child_execution(fd[2]);
	}
	pid2 = fork();
	if(pid2 < 0)
	{
		perror("ERROR");
	}

	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	close(fd[0]);
	close(fd[1]);
	//parent_execution(data);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return(0);
}*/