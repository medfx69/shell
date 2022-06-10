/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:02:51 by mboukhal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/04 18:16:32 by mait-aad         ###   ########.fr       */
=======
/*   Updated: 2022/06/09 14:52:13 by mboukhal         ###   ########.fr       */
>>>>>>> 7f851571fc338ca28993697f67270db40ba02878
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
# define  BACKSLASH     '\\'
# define  SINGLEQUOT    '\''
# define  DOUBLEEQUOT   '\"'
# define  DOLLAR        '$'
//      next operation
# define  SIMICOLON     ';'     //  59
# define  PIPE          '|'     //  124
# define  SRINPUT       '<'     //  60
# define  SROUTPUT      '>'     //  62
# define  DINPUT        "<<"    //  180 = '<' * 3
# define  DOUTPUT       ">>"    //  186 = '>' * 3 
# define  SYNTAXERR     300


typedef struct list
{
    char        *cmd;
    int         n;
    struct list *next;
    struct list *rev;
} list_t;

/*
    cmd:
        line to execute;
    next:
        next operation to do;
    last:
        if not 0 ask for next "next_operation(cmd);"
*/

/*-------------------------------------*/
//      parsing functions
/*-------------------------------------*/

list_t *pars_init(char *cmd);
void    pars_end(list_t *list);
/*-------------------------------------*/

/*
    execution part:
        exec():
            resolvine exection "execve" "getenv"
*/
<<<<<<< HEAD
// int     ft_exec(char **cmd);
// void    ft_start(char *cmd);
// void    ft_cd(char *dir);
// void    ft_pwd(void);
// char    **pars(char *cmd);
// void	end(void);
=======

int     ft_exec(char *cmd);
void    ft_start(char *cmd);
void    ft_cd(char *dir);
void    ft_pwd(void);
void    ft_env(char **env);
void	end(void);
>>>>>>> 7f851571fc338ca28993697f67270db40ba02878

#endif // !MINISHELL_H

 //    ls -a    "dir"    ;   cat "file"  