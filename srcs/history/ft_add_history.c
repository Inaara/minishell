
#include <minishell.h>

static int	ft_add_file(const char *filename, char *str)
{
	int fd;

	fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd != -1)
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		close(fd);
	}
	else
		return (-1);
	return (0);
}

static int	ft_add_list(t_shell *shell, char *str)
{
	ft_l_lst_cr_front(&(shell->history), ft_strdup(str));
	return (0);
}

int			ft_add_history(t_shell *shell, const char *filename, char *str)
{
	ft_add_file(filename, str);
	ft_add_list(shell, str);
	shell->current = NULL;
	return (0);
}
