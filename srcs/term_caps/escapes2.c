
#include <minishell.h>

void	insert_symbol(t_term *tc)
{
	tc->i = 0;
	ft_strcpy(&(tc->buf[0]), &(tc->line[tc->iter]));
	while (tc->i < tc->l)
	{
		tc->line[tc->iter] = tc->str1[tc->i];
		tc->iter++;
		tc->i++;
		tc->line[tc->iter] = 0;
	}
	ft_strcpy(&(tc->line[tc->iter]), tc->buf);
	tc->i = 0;
	while (tc->i++ < tc->l)
		tputs(cursor_right, 1, ft_putchar);
	tc->i = 0;
	while (tc->i++ < tc->iter)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
	}
	write(1, tc->line, ft_strlen(tc->line));
	tc->i = 0;
	while (tc->i++ < (int)ft_strlen(tc->line) - tc->iter)
		tputs(cursor_left, 1, ft_putchar);
}

void	back_space(t_term *tc)
{
	if (tc->iter > 0)
	{
		tc->iter--;
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		ft_memmove(&(tc->line[tc->iter]), &(tc->line[tc->iter + 1]),
			ft_strlen(tc->line + tc->iter));
	}
}

void	history_up(t_term *tc, t_shell *shell)
{
	char *str;

	str = ft_history_up(shell);
	if (str && ft_strlen(str) != 0)
	{
		while (tc->iter-- >= 0)
			tputs(cursor_left, 1, ft_putchar);
		tputs(cursor_right, 1, ft_putchar);
		tc->iter++;
		tputs(tgetstr("ce", 0), 1, ft_putchar);
		ft_strcpy(&(tc->line[0]), str);
		write(1, tc->line, ft_strlen(tc->line));
		tc->iter = ft_strlen(tc->line);
	}
}

void	history_down(t_term *tc, t_shell *shell)
{
	char *str;

	str = ft_history_down(shell);
	if (str && ft_strlen(str) != 0)
	{
		while (tc->iter-- >= 0)
			tputs(cursor_left, 1, ft_putchar);
		tputs(cursor_right, 1, ft_putchar);
		tc->iter++;
		tputs(tgetstr("ce", 0), 1, ft_putchar);
		ft_strcpy(&(tc->line[0]), str);
		write(1, tc->line, ft_strlen(tc->line));
		tc->iter = ft_strlen(tc->line);
	}
}

void	ctrl_c(t_term *tc)
{
	tc->line[0] = '\0';
	tc->str1[0] = '\n';
	tc->str1[1] = '\0';
}
