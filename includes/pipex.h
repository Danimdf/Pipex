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
int	valid_params(t_data *data);

//utils
void	ft_bzero(void *s, size_t n);
int	ft_strncmp(const char *str1, const char *str2, size_t n);

#endif