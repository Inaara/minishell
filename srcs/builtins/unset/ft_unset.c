
#include <minishell.h>

int	ft_unset(char **argv, char ***envp, char ***export)
{
	int i;
	int len;

	i = 0;
	len = ft_arrlen(argv);
	if (len == 0)
		return (0);
	else
	{
		while (argv[i])
		{
			ft_unset_envp_export(argv[i], export, envp);
			i++;
		}
	}
	return (0);
}
