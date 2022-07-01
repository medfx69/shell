/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:15:17 by mboukhal          #+#    #+#             */
/*   Updated: 2022/07/01 14:25:41 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

static int	is_eqoul(char	*s1, char	*s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(s2[i])
	{
		if (s2[i] == s1[j])
			j++;
		else
			return (0);
		i++;
	}
	return (1);
}

char	*ft_pwd(void)
{
	char	*tmp;
	int		i;

	tmp = getcwd(NULL, 0);
	if (tmp == NULL)
	{
		i = -1;
		while (env[++i])
		{
			if (is_eqoul(env[i], "PWD") == 1)
				break ;
		}
		return (env[1]);
	}
	return (tmp);
}
