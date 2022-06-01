/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:02:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/06/01 06:43:34 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void loop(char *cmd)
{
    while (1)
    {
        cmd = readline( "Minishell> " );
        if (cmd[0])
        {
            add_history(cmd);
            ft_start(cmd);
        }
        if (cmd[0] == 'c' && cmd[1] == 'l')
            clear_history();
        if (cmd[0] == 'q' && cmd[1] == 't')
            break;
        free(cmd);
    }
}


int main(void)
{
    char *cmd = NULL;
    char *line;
    // int i;
    // DIR *dp;
    // struct dirent *dirp;

    // line = getenv("PATH");
    // printf("%s\n\n\n\n", line);

    // line = getcwd(NULL, 0);
    // printf("|%s|\n", line);
    // free(line);
    // chdir("../..");
    // ft_cd(NULL);

    ft_exec("lss -l");
    
    // line = getcwd(NULL, 0);
    // printf("|%s|\n", line);
    // free(line);

    // i = isatty(1);
    // printf("|%d|\n", i);
    // int i = 0;
    // while (env[i])
    //     printf("|%s|\n", env[i++]);
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
    loop(cmd);

    return (EXIT_SUCCESS);
}