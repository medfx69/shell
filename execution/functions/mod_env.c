/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:27:46 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/28 15:45:38 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"
int	is_eqoul(char	*s1, char	*s2)
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

void	mod_env(char	**pwds)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (is_eqoul(env[i], "PWD") == 1)
		{
			pwds[1] = ft_strjoin("PWD=", pwds[1]);
			env[i] = pwds[1]; 
		}
	}
	i = -1;
	while (env[++i])
	{
		if (is_eqoul(env[i], "OLDPWD") == 1)
		{
			pwds[0] = ft_strjoin("OLDPWD=", pwds[0]);
			env[i] == pwds[0];
		}
	}
}