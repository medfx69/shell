/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:55:35 by mboukhal          #+#    #+#             */
/*   Updated: 2022/05/31 13:09:00 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *ft_join_path(char *path, char *cmd)
{
    int     len_p;
    int     len_cmd;
    char    *line;
    int     i;
    int     j;

    len_p = ft_strlen(path);
    len_cmd = ft_strlen(cmd);
    line = malloc(sizeof(char) * (len_p + len_cmd) + 2);
    if (!line)
        return (NULL);
    i = 0;
    j = 0;
    while (path[i])
    {
        line[i] = path[i];
        i++;
    }
    line[i++] = '/';
    while (cmd[j])
        line[i++] = cmd[j++];
    line[i] = '\0';
    return (line);
}

int ft_exec(char *cmd)
{
    char **path_s;
    char **cmd_s;
    char *line;
    int     i;

    i = -1;
    cmd_s = ft_split(cmd, ' ');
    path_s = ft_split(getenv("PATH"), ':');
    while(path_s[++i])
    {
        line = ft_join_path(path_s[i], cmd_s[0]);
        if (!access(line, X_OK))
            break;
        free(line);
    }
    if (!line)
        return (0);

    printf("<|%s|>\n", line);
    int id = fork();
    if (id == 0)
    {
        
        execve(line, cmd_s, NULL);
    }


    printf("<|%s|>\n", line);
    // free splits
    i = -1;
    while(path_s[++i])
        free(path_s[i]);
    free(path_s);
    i = -1;
    while(cmd_s[++i])
        free(cmd_s[i]);
    free(cmd_s);
    // end free splits 

    return (0);
}
