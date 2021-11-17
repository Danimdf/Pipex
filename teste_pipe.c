/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:34:02 by dmonteir          #+#    #+#             */
/*   Updated: 2021/11/16 20:49:56 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER 256

int main()
{
	int fd[2];
	pid_t pid;

	//Criei um pipe
	if(pipe(fd) < 0)
	{
		perror("pipe");
		return -1;
	}
	// criei um processo filho
	if ((pid = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}
	//criei um pŕocesso pai
	if(pid > 0)
	{
		close(fd[0]);

		char str[BUFFER] = "Gatinho 123";
		printf("String enviado pelo processo pai: '%s'", str);

		write(fd[1], str, sizeof(str) + 1);
		exit(0);
	} else {
		char str_recebida[BUFFER];

		close(fd[1]);

		read(fd[0], str_recebida, sizeof(str_recebida));

		printf("\nString lida pelo filho no Pipe : '%s'\n\n", str_recebida);
		console.log(str_recebida);
		exit(0);
	}
	return (0);
}