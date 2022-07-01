/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:22:32 by mait-aad          #+#    #+#             */
/*   Updated: 2022/07/01 18:50:26 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXI_H
# define EXI_H
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

// # include "../../minishell.h"
// # include "../ft.h"

typedef struct s_data
{
	char	**vars;
	char	*key;
	char	*val;
	struct s_data *next;
}		t_data;

char	**env;
char	*ft_strdup(char	*s1);
char	*ft_pwd(void);
char	*ft_cd(char *dir);
void	mod_env(char	**pwds);
char 	**add(char *s2);
char	*ft_export(char **in);
char	*ft_echo(char	**inputs, int newlin);
char	*add_to_a_file(char	*in, char	*file);
char	*create_and_to_a_file(char	*in, char	*file);
char	*ft_strjoin(char	*s1, char	*s2);
char	*ft_substr(char const *s, int start, int len);
char	**ft_split(char const *s, char c);
char	*ft_unset(char	*para);
int		ft_strlen(char *str);

#endif