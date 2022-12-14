
#include <minishell.h>

int		ft_before_cmd(t_cmd_pipe *cmd_pipe, int num, int cnt)
{
	if (num == 0)
	{
		dup2(cmd_pipe->pipes[0][1], 1);
	}
	if (num > 0)
	{
		dup2(cmd_pipe->pipes[num - 1][0], 0);
		if (num < cnt - 1)
		{
			dup2(cmd_pipe->pipes[num][1], 1);
		}
	}
	if (num == cnt - 1)
	{
		close(cmd_pipe->pipes[num - 1][0]);
		dup2(cmd_pipe->old_out, 1);
	}
	return (0);
}

int		ft_after_cmd(t_cmd_pipe *cmd_pipe, int num, int cnt)
{
	if (num == 0)
	{
		close(cmd_pipe->pipes[num][1]);
	}
	if (num > 0)
	{
		close(cmd_pipe->pipes[num - 1][0]);
		if (num < cnt - 1)
		{
			close(cmd_pipe->pipes[num][1]);
			dup2(cmd_pipe->old_out, 1);
		}
	}
	return (0);
}
