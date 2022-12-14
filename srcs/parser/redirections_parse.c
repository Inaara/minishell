
#include <minishell.h>

char	*write_open(char *str, long long int **fd, t_shell *shell)
{
	char *file_name;

	str = parse_by_space(str, &file_name, shell);
	if ((*fd)[1] != 1)
		close((*fd)[1]);
	(*fd)[1] = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if ((*fd)[1] == -1)
	{
		str = parse_error(&(*fd), str, errno);
		(*fd)[5] = (long long int)file_name;
	}
	else
		free(file_name);
	return (str);
}

char	*append_open(char *str, long long int **fd, t_shell *shell)
{
	char *file_name;

	str = parse_by_space(str, &file_name, shell);
	if ((*fd)[1] != 1)
		close((*fd)[1]);
	(*fd)[1] = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if ((*fd)[1] == -1)
	{
		str = parse_error(&(*fd), str, errno);
		(*fd)[5] = (long long int)file_name;
	}
	else
		free(file_name);
	return (str);
}

char	*read_open(char *str, long long int **fd, t_shell *shell)
{
	char *file_name;

	str = parse_by_space(str, &file_name, shell);
	if ((*fd)[0] != 0)
		close((*fd)[0]);
	(*fd)[0] = open(file_name, O_RDONLY, 0644);
	if ((*fd)[0] == -1)
	{
		str = parse_error(&(*fd), str, errno);
		(*fd)[5] = (long long int)file_name;
	}
	else
		free(file_name);
	return (str);
}
