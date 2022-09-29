
#include <minishell.h>

int	ft_oldpwd(char *oldpwd, t_shell *shell)
{
	char	*argv_ex[3];
	char	*pwds;
	int		o_pw;

	o_pw = ft_find_envp_id("OLDPWD", shell->export);
	if (o_pw != -1)
	{
		pwds = ft_strjoin("OLDPWD=", oldpwd);
		argv_ex[0] = "export";
		argv_ex[1] = pwds;
		argv_ex[2] = NULL;
		ft_command("export", argv_ex, shell, shell->fds);
		free(pwds);
	}
	return (0);
}
