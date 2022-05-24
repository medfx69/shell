/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:02:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/05/24 18:15:30 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
    char *l;

    while (1)
    {
        l = readline( "Minishell> " );
        if (l[0] == ':' && l[1] == 'q')
        {
            free(l);
            break ;
        }
        printf("%s\n", l);

        free(l);
    }
    return (EXIT_SUCCESS);
}