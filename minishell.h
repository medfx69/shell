/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:02:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/06/06 11:41:27 by mboukhal         ###   ########.fr       */
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
# define  SINGLEQUOT    "'"
# define  DOUBLEEQUOT   "\""
# define  DOLLAR        "$"
//      next operation
# define  SIMICOLON     ";"     //  1
# define  PIPE          "|"     //  2
# define  SRINPUT       "<"     //  3
# define  SROUTPUT      ">"     //  4
# define  DINPUT        "<<"    //  5
# define  DOUTPUT       ">>"    //  6

typedef struct minishell
{
    char *pwd;

}   mini_t;

/*
    cmd:
        line to execute;
    next:
        next operation to do;
    last:
        if not 0 ask for next "next_operation(cmd);"
*/
typedef struct pars
{
    char *cmd;
    int next;
    int last;

}   pars_t;



/*
    execution part:
        exec():
            resolvine exection "execve" "getenv"
*/
int     ft_exec(char *cmd);
void    ft_start(char *cmd);
void    ft_cd(char *dir);
void    ft_pwd(void);
char    **pars(char *cmd);
void    ft_env(char **env);
void	end(void);

#endif // !MINISHELL_H

//    ls -a    "dir"    ;   cat "file"   