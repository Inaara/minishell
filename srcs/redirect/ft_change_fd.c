
#include <minishell.h>

int	ft_change_fd(t_redirect *red, long long int *fds)
{
	if (fds[0] != 0)
	{
		red->old_std_in = dup(0);
		dup2(fds[0], 0);
		close(fds[0]);
	}
	if (fds[1] != 1)
	{
		red->old_std_out = dup(1);
		dup2(fds[1], 1);
		close(fds[1]);
	}
	if (fds[2] != 2)
	{
		red->old_std_err = dup(2);
		dup2(fds[2], 2);
		close(fds[2]);
	}
	return (0);
}
