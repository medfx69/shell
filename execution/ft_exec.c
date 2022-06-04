/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:55:35 by mboukhal          #+#    #+#             */
/*   Updated: 2022/06/04 13:29:32 by mboukhal         ###   ########.fr       */
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

static void free_it(char **s, char **ss, char *line)
{
    int i;

    i = -1;
    while(s[++i])
        free(s[i]);
    free(s);
    i = -1;
    while(ss[++i])
        free(ss[i]);
    free(ss);
    free(line);
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
    if (!path_s[i])
    {
        ft_putstr_fd("minishell: command not found: ", 2);
        ft_putendl_fd(cmd_s[0], 2);
        // free splits
        free_it(path_s, cmd_s, line);
        return (0);
    }

    // printf("<|%s|>\n", line);
    int id = fork();
    if (id == 0)
    {
        
        execve(line, cmd_s, NULL);
    }
    waitpid(id, NULL, 0);


    // printf("<|%s|>\n", line);
    // free splits
    free_it(path_s, cmd_s, line);

    // end free splits 

    return (0);
}
