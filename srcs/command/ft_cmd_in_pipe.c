
#include <minishell.h>

static void	ft_wait_child_process(void)
{
	int k;
	int status;

	k = 0;
	while (k < g_forks)
	{
		wait(&status);
		if (WIFSIGNALED(status) && WTERMSIG(status) == 9)
		{
			write(1, "Killed: 9\n", 10);
			exit(137);
		}
		if (WEXITSTATUS(status) == 137)
		{
			exit(137);
		}
		g_exit_status = WEXITSTATUS(status);
		k++;
	}
	g_forks = 0;
}

static int	ft_check_fd_errno(t_data *data, int i)
{
	if (data->fds[i][3] != 0)
	{
		if (data->fds[i][3] == 128)
		{
			print_syntax_error(data->fds[i][4]);
			return (1);
		}
		else
		{
			errno = data->fds[i][3];
			write(2, "minishell: ", 11);
			ft_putstr_fd((char *)(void*)(data->fds[i][5]), 2);
			free((char *)(void*)(data->fds[i][5]));
			write(2, ": ", 2);
			ft_print_errno();
			errno = 0;
			return (2);
		}
	}
	return (0);
}

static void	ft_check_exit_status(t_cmd_pipe *cmd_pipe, int *j)
{
	if (g_exit_status != 0)
	{
		ft_return_standat_fd(cmd_pipe);
		*j = 0;
	}
}

static void	ft_cicle_pipe(t_cmd_pipe *cmd_pipe, t_data *data, t_shell *shell)
{
	int i;
	int j;
	int err;

	err = 0;
	i = 0;
	j = 0;
	ft_init_cmd_pipe(cmd_pipe, data->size);
	while (i < data->size)
	{
		err = ft_check_fd_errno(data, i);
		if (err == 1)
		{
			g_exit_status = 1;
			break ;
		}
		ft_before_cmd(cmd_pipe, j, data->size);
		if (err != 2)
			g_exit_status = ft_command(data->cmds[i][0],
				data->cmds[i], shell, data->fds[i]);
		ft_after_cmd(cmd_pipe, j, data->size);
		ft_check_exit_status(cmd_pipe, &j);
		j++;
		i++;
	}
}

void		ft_cmd_in_pipe(t_data *data, t_shell *shell)
{
	t_cmd_pipe	cmd_pipe;
	int			err;

	g_forks = 0;
	if (data->size == 1)
	{
		err = ft_check_fd_errno(data, 0);
		if (data->cmds[0][0] == NULL)
		{
			g_exit_status = 1;
			return ;
		}
		if (!err)
			g_exit_status = ft_command(data->cmds[0][0],
				data->cmds[0], shell, data->fds[0]);
		else
			g_exit_status = 1;
	}
	else
		ft_cicle_pipe(&cmd_pipe, data, shell);
	ft_wait_child_process();
	ft_free_cmd_pipe(&cmd_pipe, data->size);
	ft_return_standat_fd(&cmd_pipe);
}
