/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:02:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/06/04 18:16:32 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <errno.h>
# include <limits.h>
# include "utils/libft.h"

# define  PROMPT        "Minishell> "
# define  BACKSLASH     "\\"
# define  SIMICOLON     ";"
# define  SINGLEQUOT    "'"
# define  DOUBLEEQUOT   "\""
# define  DOLLAR        "$"
# define  SRINPUT       "<"
# define  DINPUT        "<<"
# define  SROUTPUT      ">"
# define  DOUTPUT       ">>"
# define  PIPE          "|"

typedef struct minishell
{
    char *pwd;

}   mini_t;

/*
    execution part:
        exec():
            resolvine exection "execve" "getenv"
*/
// int     ft_exec(char **cmd);
// void    ft_start(char *cmd);
// void    ft_cd(char *dir);
// void    ft_pwd(void);
// char    **pars(char *cmd);
// void	end(void);

#endif // !MINISHELL_H