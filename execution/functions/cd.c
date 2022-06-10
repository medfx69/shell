/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:47:42 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/10 12:24:39 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


void	ft_cd(char *dir)
{
	int	i;

	if (!dir || (dir[0] == '~' && dir[1] == '\0') || dir[0] == '\0')
		chdir(getenv("HOME"));
	else 
	{
		i = chdir(dir);
		if (i == -1)
			printf("cd: no such file or directory:%s", dir);
	}
}
