/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:02:55 by mboukhal          #+#    #+#             */
/*   Updated: 2022/05/29 17:28:11 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_start(char *cmd, char **env)
{
    (void) env;
    char **cmd_splited;
    int i;

    cmd_splited = ft_split(cmd, ';');
    i = -1;
    // while (cmd_splited[++i])
    // {
    if (!ft_strncmp(cmd_splited[0], "cd", 2))
    {
        printf("==|%s| |%s|\n", cmd_splited[i], getcwd(NULL, 0));
        ft_cd((cmd_splited[3]));
        printf("==|%s| |%s|\n", cmd_splited[i], getcwd(NULL, 0));
    }

    // }
    printf("|%s|\n", cmd);
    if (cmd[0] == 'c' && cmd[1] == 'd')
        ft_cd(cmd);
    i = -1;
    while(cmd_splited[++i])
        free(cmd_splited[i]);
    free(cmd_splited);
    // ft_exec(cmd, env);
}