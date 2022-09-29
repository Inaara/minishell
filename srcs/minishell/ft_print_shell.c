
#include <minishell.h>

void	ft_print_shell(void)
{
	ft_putstr_fd("\033[36m", 1);
	ft_putstr_fd("minishell", 1);
	ft_putstr_fd("\033[37m", 1);
	if (g_exit_status == 0)
	{
		ft_putstr_fd("\033[32m", 1);
		ft_putstr_fd("(o-_-o)", 1);
		ft_putstr_fd("\033[37m", 1);
	}
	else
	{
		ft_putstr_fd("\033[31m", 1);
		ft_putstr_fd("(＞-＜)", 1);
		ft_putstr_fd("\033[37m", 1);
	}
	ft_putstr_fd("\033[36m", 1);
	ft_putstr_fd("$> ", 1);
	ft_putstr_fd("\033[37m", 1);
}
