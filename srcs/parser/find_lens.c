
#include <minishell.h>

char	*some_ifs(char *str)
{
	if (*str && *str == '"')
	{
		str++;
		while (*str && *str != '"')
		{
			if (*str && *str == '\\')
				str++;
			str++;
		}
		str++;
	}
	if (*str && *str == '\'')
	{
		str++;
		while (*str && *str != '\'')
			str++;
		str++;
	}
	if (*str && not_one_of_the_set(*str, " |;"))
		str++;
	return (str);
}

char	*skip_redirection(char *str)
{
	while (*++str && *str == ' ')
		;
	while (*str && not_one_of_the_set(*str, " |;"))
		str = some_ifs(str);
	return (str);
}

char	*some_if_elses(char *str, int *len)
{
	if (*str && *str == '"')
	{
		while (*++str && *str != '"')
			;
		str++;
	}
	else
	{
		if (*str && *str && *str == ' ')
		{
			while (*str && *str == ' ')
				str++;
			if (*str != '>' && *str != '<')
				(*len)++;
			else
				str = skip_redirection(str);
		}
		else
			str++;
	}
	return (str);
}

int		find_cmd_len(char *str)
{
	int len;

	len = 1;
	while (*str && *str == ' ')
		str++;
	while (*str && *str != '|' && *str != ';')
	{
		if (*str && *str == '\'')
		{
			while (*++str && *str != '\'')
				;
			str++;
		}
		else
			str = some_if_elses(str, &len);
	}
	if (*str == '|' && *(str - 1) && *(str - 1) == ' ')
		len--;
	return (len);
}

int		find_cmds_count(char *str)
{
	int len;

	len = 1;
	while (*str)
	{
		if (*str && *str == '\'')
		{
			str++;
			while (*str && *str != '\'')
				str++;
		}
		if (*str && *str == '"')
		{
			str++;
			while (*str && *str != '"')
				str++;
		}
		if (*str && *str == '|')
			len++;
		if (*str && *str == ';')
			break ;
		str++;
	}
	return (len);
}
