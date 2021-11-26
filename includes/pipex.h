#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>

typedef struct s_data
{
	char path;
	char cmd1;
	char cmd2;
	int		ac;
	//char	*ev;
} t_data;

int		main(int argc, char *argv[], char **envp);
void	valid_params(t_data *data, char **argv, char **env);
char	get_path(t_data *data, char **argv, char **env);

//utils
int	ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strdup(const char *str1);
char	**ft_split(const char *s, char c);

#endif