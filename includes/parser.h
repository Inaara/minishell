
#ifndef PARSER_H
# define PARSER_H

# include <minishell.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "libft.h"
# include <fcntl.h>

typedef struct	s_data
{
	char			***cmds;
	long long int	**fds;
	int				size;
	char			**err_txt;
}				t_data;

#endif
