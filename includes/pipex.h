#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdio.h>

typedef struct s_data
{
	int		ac;
	char	**av;
	char	**ev;
} t_data;

int		main(int argc, char **argv, char **envp);
void	valid_params(t_data *data);
void	ft_bzero(void *s, size_t n);




#endif