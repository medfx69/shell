/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:55:35 by mboukhal          #+#    #+#             */
/*   Updated: 2022/05/25 11:10:27 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_exec(char **cmd, char **env)
{
    // char    *path = NULL;
    int     i;
    (void) cmd;

    i = 0;
    while (env[i][0] != 'P' && env[i][1] != 'A' &&
        env[i][2] != 'T' &&env[i][3] != 'H')
        i++;
    printf("|%s|\n", env[i]);
    return (0);
    // execve(cmd[0], cmd, path);
}
