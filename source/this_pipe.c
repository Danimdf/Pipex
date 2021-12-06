/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:50:56 by dmonteir          #+#    #+#             */
/*   Updated: 2021/12/06 17:31:22 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
/* input = ./pipex infile "grep a1" "wc -w" outfile
is the same =  “< infile grep a1 | wc -w > outfile” */

/*int	parent_execution(t_data *data)
{

}*/

/* void	child_execution1(int fd)
{
	close(fd[0]);
	if (dup2(fd[1]), STDOUT_FILENO) < 0)
		perror("Dup2 Not Found");
	close(fd[1])

	close(fd[1]);
} */


int this_pipex(t_data *data)
{
 	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 < 0)
		perror ("Fork failed!\n");
	if (pid1 == 0)
	{
		//child_execution1(fd[2]);
	}
	pid2 = fork();
	if(pid2 < 0)
		perror("Fork Not Found!");
	if (pid2 == 0)
	{
		//child_execution2(fd[2]);
	}
	//parent_execution(data);
	//waitpid(pid1, NULL, 0);
	//waitpid(pid2, NULL, 0);
	return(0);
}