#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>

typedef struct s_data
{
	char	**path;
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	int		ac;
	//char	*ev;
} t_data;

int		main(int argc, char *argv[], char **envp);
void	valid_params(t_data *data, char **argv, char **env);
char	get_path(t_data *data, char **argv, char **env);
void	check_path_cmd1(t_data *data);

//utils
int	ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strdup(const char *str1);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

#endif