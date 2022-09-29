
#include <minishell.h>

int	ft_is_original_fd(long long int *fds)
{
	if (fds[0] == 0 && fds[1] == 1 && fds[2] == 2)
		return (1);
	return (0);
}
