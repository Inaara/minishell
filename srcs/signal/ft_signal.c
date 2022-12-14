
#include <minishell.h>

void			ft_signal_cltr_c(int sig)
{
	(void)sig;
	g_exit_status = 1;
	write(1, "\n", 1);
	g_exit_status = 1;
	ft_print_shell();
}

static	void	ft_signal_quit(int sig)
{
	write(1, "\b\b  \b\b", 6);
	write(1, "^\\Quit: ", 8);
	ft_putnbr_fd(sig, 1);
	write(1, "\n", 1);
	g_signal = 131;
}

static	void	ft_sigterm(int sig)
{
	(void)sig;
}

static	void	ft_signal_sigchld(int sig)
{
	(void)sig;
}

void			ft_signal(void)
{
	signal(SIGQUIT, ft_signal_quit);
	signal(SIGCHLD, ft_signal_sigchld);
	signal(SIGTERM, ft_sigterm);
}
