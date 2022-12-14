
#include <minishell.h>

int	ft_return_fd(t_redirect *red, long long int *fds)
{
	if (fds[0] != 0)
	{
		dup2(red->old_std_in, 0);
		close(red->old_std_in);
	}
	if (fds[1] != 1)
	{
		dup2(red->old_std_out, 1);
		close(red->old_std_out);
	}
	if (fds[2] != 2)
	{
		dup2(red->old_std_err, 2);
		close(red->old_std_err);
	}
	return (0);
}
