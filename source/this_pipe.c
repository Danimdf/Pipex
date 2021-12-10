/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:50:56 by dmonteir          #+#    #+#             */
/*   Updated: 2021/12/09 21:20:42 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
/* input = ./pipex infile "grep a1" "wc -w" outfile
is the same =  “< infile grep a1 | wc -w > outfile” */

void	child_execution_2(t_data *data)
{
	data->file_out = open(data->file2, O_RDWR | O_CREAT | O_TRUNC, 0644);
	close(data->fd[0]);
	close(data->fd[1]);

	if (dup2(data->fd[0], STDIN_FILENO) < 0)
	{
		perror("Dup2 not found!");
	}
	if (dup2(data->file_out, STDOUT_FILENO) < 0)
	{
		perror("Dup2 2 not found!");
	}
	//printf("\n%s\n", data->)

	//check_path_cmd1(data->av[2], data);
	execve(data->path2, data->cmd2, data->ev);
}


void	child_execution_1(t_data *data)
{
	if (dup2(data->fd[0], STDOUT_FILENO) < 0)
	{
		perror("Dup2 not found!");
	}
	close(data->fd[0]);
	close(data->fd[1]);
	printf("\n%s\n", data->file1);
	data->file_in = open(data->file1, O_RDONLY);
	//printf("\n%s\n", data->)
	if (data->file_in == -1)
		perror("Dup2 not found!");
	//data->cmd1 = ft_split(*data->cmd1, " ");
	//splita o cmd e manda pro comando.

	//check_path_cmd1(data->av[2], data);
	execve(data->path1, data->cmd1, data->ev);
}


int this_pipex(t_data *data)
{
	int	pid1;
	int	pid2;

	if (pipe(data->fd) < 0)
	{
		perror("Pipe not found!");
	}
	pid1 = fork();
	if (pid1 < 0)
		perror ("Fork 1 failed!\n");
	if (pid1 == 0)
	{
		child_execution_1(data);
	}
	pid2 = fork();
	if(pid2 < 0)
		perror("Fork 2 Not Found!");
	if (pid2 == 0)
	{
		child_execution_2(data);
	}
	waitpid(-1, NULL, 0);
	return(0);
}