
#include <minishell.h>

int		ft_find_builtins(char *comand)
{
	if (ft_strcmp(comand, "echo") == 0)
		return (1);
	if (ft_strcmp(comand, "cd") == 0)
		return (1);
	if (ft_strcmp(comand, "pwd") == 0)
		return (1);
	if (ft_strcmp(comand, "export") == 0)
		return (1);
	if (ft_strcmp(comand, "unset") == 0)
		return (1);
	if (ft_strcmp(comand, "env") == 0)
		return (1);
	if (ft_strcmp(comand, "exit") == 0)
		return (1);
	return (0);
}
