
#include <minishell.h>

t_data	get_line(t_shell *shell)
{
	char	*str;
	pid_t	parent;

	while (1)
	{
		parent = getppid();
		if (parent == 1)
		{
			ft_print_shell();
			write(1, "exit\n", 5);
			exit(137);
		}
		errno = 0;
		ft_print_shell();
		str = term_caps(shell);
		if (ft_strlen(str) > 0)
			ft_add_history(shell, "history", str);
		shell->j = 0;
		if (syntax_error_detect(str))
			;
		else if (errno == 0)
			parse(str, shell);
		else
			ft_print_errno();
		free(str);
	}
}
