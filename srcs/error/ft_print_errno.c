
#include <minishell.h>

void	ft_print_errno(void)
{
	char *errorbuf;

	errorbuf = strerror(errno);
	ft_putstr_fd(errorbuf, 2);
	write(2, "\n", 1);
}
