/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:02:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/05/25 20:16:28 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
    char *cmd;
    (void)ac;
    (void)av;
    // int i;

    while (1)
    {
        cmd = readline( "Minishell> " );
        if (cmd[0])
        {
            add_history(cmd);
            ft_start(cmd, env);
        }
        if (cmd[0] == 'c' && cmd[1] == 'x')
            clear_history();
        free(cmd);
    }
    return (EXIT_SUCCESS);
}