/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:02:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/06/01 15:46:25 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
            break;
        }
        free(cmd);
    }
}


int main(void)
{
    // char *cmd = NULL;
    char *line;
    // int i;
    // DIR *dp;
    // struct dirent *dirp;


    // no need to be freed
    line = getenv("\?");
    printf("<%s>\n", line);

    line = getcwd(NULL, 0);
    printf("|%s|\n", line);
    free(line);
    // chdir("../..");
    // ft_cd(NULL);

    ft_exec("ls -l");
    
    // line = getcwd(NULL, 0);
    // printf("|%s|\n", line);
    // free(line);

    // i = isatty(1);
    // printf("|%d|\n", i);
    line = ttyname(1);
    printf("|%s|\n", line);
    free(line);
    // printf("|%d|\n", ttyslot());
    // dp = opendir("utils");
    // if (dp)
    // {
    //     while ((dirp = readdir(dp)) != NULL)
    //         printf("%s\n", dirp->d_name);
    //     printf("\n\n\n\n");
    // }

    // signal(SIGINT, read_line);
    // loop(cmd);

    // system("leaks minishell");

    return (EXIT_SUCCESS);
}