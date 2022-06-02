/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:02:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/06/01 18:50:23 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    cheak_exit_val(char *cmd)
{
    int i;
    char max[22];
    int len;
    
    i = 0;
    while (cmd[i] == ' ' || cmd[i] == '\n' || cmd[i] == '\t'
        || cmd[i] == '\r' || cmd[i] == '\f')
        i++;
    cmd = &cmd[i];
    if (*cmd == '\0')
        exit (0);
    len = ft_strlen(cmd);
    ft_strlcat("9223372036854775807", max, 19);
    i = 0;
    while((cmd[i] <= '9' || cmd[i] >= '0') && cmd[i])
        i++;
    if (len < 19 && len > 3)
        exit (255);
    else if (len > 19 || i != len)
    {
        ft_putstr_fd("minishell: exit: ", 2);
        ft_putstr_fd(cmd, 2);
        ft_putendl_fd(": numeric argument required", 2);
        exit (255);
    }
    else if (len == 19)
    {
        i = 0;
        while((cmd[i] <= '9' || cmd[i] >= '0')
            && max[i] <= cmd[i] && cmd[i])
            i++;
        if (i != len)
            exit (255);
    }
    len = ft_atoi(cmd);
    if (len <= 255)
        exit ((unsigned int)len);
    else
        exit (255);
}

void loop(char *cmd)
{
    char **cmd_p;
   int i = 0;

    while (1)
    {
        cmd = readline( "Minishell> " );
        if (cmd[0])
        {
            add_history(cmd);
            cmd_p = pars(cmd);
            // ft_start(cmd);
            while (cmd_p[i])
                free(cmd_p[i++]);
            free(cmd_p);
        }
        if (cmd[0] == 'c' && cmd[1] == 'l')
            clear_history();
        if (cmd[0] == 'e' && cmd[1] == 'x'
            && cmd[2] == 'i' && cmd[3] == 't')
        {
            free(cmd);
            printf("|%s| |%lld| \n", &cmd[5], LLONG_MAX);
            cheak_exit_val(&cmd[4]);
            break;
        }
        free(cmd);
    }
}


int main(void)
{
    char *cmd = NULL;
    // char *line;
    // int i;
    // DIR *dp;
    // struct dirent *dirp;


    // no need to be freed
    // line = getenv("\?");
    // printf("<%s>\n", line);

    // line = getcwd(NULL, 0);
    // printf("|%s|\n", line);
    // free(line);
    // chdir("../..");
    // ft_cd(NULL);

    // ft_exec("ls -l");
    
    // line = getcwd(NULL, 0);
    // printf("|%s|\n", line);
    // free(line);

    // i = isatty(1);
    // printf("|%d|\n", i);
    // line = ttyname(1);
    // printf("|%s|\n", line);
    // free(line);
    // printf("|%d|\n", ttyslot());
    // dp = opendir("utils");
    // if (dp)
    // {
    //     while ((dirp = readdir(dp)) != NULL)
    //         printf("%s\n", dirp->d_name);
    //     printf("\n\n\n\n");
    // }

    // signal(SIGINT, read_line);
    loop(cmd);

    // system("leaks minishell");

    return (EXIT_SUCCESS);
}