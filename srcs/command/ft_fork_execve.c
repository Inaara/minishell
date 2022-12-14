
#include <minishell.h>

static void	ft_descendant(char *comand, char **argv, char **envp)
{
	int res;

	res = execve(comand, argv, envp);
	if (res == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(comand, 2);
		ft_putstr_fd(": ", 2);
		if (errno == 2)
			ft_putstr_fd("command not found\n", 2);
		else
			ft_print_errno();
		exit(1);
	}
	exit(0);
}

int			ft_fork_and_execve_command(char *comand, char **argv, char **envp)
{
	pid_t	pid;
	int		status;

	status = 0;
	g_signal = 0;
	ft_signal_child_process();
	pid = fork();
	if (pid == 0)
		ft_descendant(comand, argv, envp);
	else if (pid == -1)
	{
		ft_print_errno();
		return (1);
	}
	else
		g_forks++;
	if (WIFSIGNALED(status) && WTERMSIG(status) == 9)
	{
		write(1, "Killed: 9\n", 10);
		exit(137);
	}
	ft_signal();
	if (g_signal != 0)
		return (g_signal);
	return (WEXITSTATUS(status));
}
