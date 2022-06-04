/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:34:43 by mboukhal          #+#    #+#             */
/*   Updated: 2022/06/04 16:32:56 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char *rm_space(char *s)
{
	int i;
	int len;
    char *start;
    char *r;
	
	i = 0;
	len = ft_strlen(s);
	while (s[i] == ' ')
		i++;
    printf("\t\t\t[%i]|%c|\n", i, s[len]);
	if (len > 0)
	{
		len--;
		while (s[len--] == ' ')
			;
		s[len + 2] = '\0';
	}
    start = (s + (sizeof(char) + i) - 1);
    printf("[%s] [%d] |%c|\n", start, len, s[len]);
	if (i > 0)
    {
        r = malloc(sizeof(char) * (len));
        ft_strlcat(r, start, len);
        printf("\n\n\t|%s|\t\n\n\n", &s[i]);
        i = -1;
        while(r[++i])
            s[i] = r[i];
        free(r);
	    return (s);
    }
    return (s);
}

// static void ft_cots(char **c)
// {
    // int     i;
    // int     j;
    // int     cote[2];

    // i = 0;
    // cote[0] = 0;
    // cote[1] = 0;
    // while (c[i])
    // {
    //     j = 0;
    //     while (c[i][j])
    //     {
    //         while (c[i][j] == DOUBLEEQUOT)
    //         {
    //             if (cote[1] == 0 && )
    //                 cote[0]++;
    //         }
    //         j++;
    //     }
    //     i++;
    // }
    


// }

char    **pars(char *cmd)
{
    char    **cmd_p;
    int     i;

    if (!cmd)
        return (NULL);
    cmd_p = ft_split(cmd, ';');
    if (cmd_p == NULL)
        return (NULL);
    i = 0;
    // ft_cots(cmd_p);
    while (cmd_p[i])
    {
        cmd_p[i] = rm_space(cmd_p[i]);
        printf("<%s>\n",cmd_p[i]);
        printf("----------------------\n");
        i++;
    }

    return (cmd_p);
}