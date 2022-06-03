/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:37:36 by mboukhal          #+#    #+#             */
/*   Updated: 2022/06/03 11:17:23 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void    ft_cd(char *dir)
{
    // DIR *dp;
    // struct dirent *dirp;

    if (!dir || (dir[0] == '~' && dir[1] == '\0'))
        chdir(getenv("HOME"));
    // line = getcwd(NULL, 0);
    // printf("|%s|\n", line);
    // free(line);
    //     dp = opendir("utils");
    // if (dp)
    // {
    //     while ((dirp = readdir(dp)) != NULL)
    //         printf("%s\n", dirp->d_name);
    //     printf("\n\n\n\n");
    // }


}