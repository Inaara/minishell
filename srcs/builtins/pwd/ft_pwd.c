
#include <minishell.h>

int	ft_pwd(char **argv, char **envp)
{
	char	*pwd;

	(void)envp;
	(void)argv;
	if (!(pwd = getcwd(NULL, 1024)))
	{
		ft_print_errno();
		return (1);
	}
	else
	{
		ft_putstr_fd(pwd, 1);
		write(1, "\n", 1);
	}
	free(pwd);
	return (0);
}
