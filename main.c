/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:02:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/05/31 13:39:28 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void loop(char *cmd, char **env)
{
    while (1)
    {
        cmd = readline( "Minishell> " );
        if (cmd[0])
        {
            add_history(cmd);
            ft_start(cmd, env);
        }
        if (cmd[0] == 'c' && cmd[1] == 'l')
            clear_history();
        if (cmd[0] == 'q' && cmd[1] == 't')
            break;
        free(cmd);
    }
}


int main(int ac, char **av, char **env)
{
    char *cmd = NULL;
    char *line;
    (void)ac;
    (void)av;
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

    // ft_exec("ls -l");
    
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
    loop(cmd, env);

    return (EXIT_SUCCESS);
}