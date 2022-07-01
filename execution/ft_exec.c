/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:23:38 by mait-aad          #+#    #+#             */
/*   Updated: 2022/07/01 18:38:38 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

// static void	free_it(char **s)
// {
// 	int	i;

// 	i = -1;
// 	while (s[++i])
// 		free(s[i]);
// 	free(s);
// }

static int	is_eqoul(char	*s1, char	*s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(s1[i])
	{
		if (s1[i] == s2[j])
			j++;
		else
			return (0);
		i++;
	}
	return (1);
}

char	*ft_exec(char	**cmd)
{
	char	*output;
	int		i;

	output = NULL;
	if (is_eqoul(cmd[0], "echo") == 1)
	{
		if (is_eqoul(cmd[1], "-n") == 1)
			output = ft_echo(cmd +2, 0);
		else	
			output = ft_echo(cmd +1, 1);
	}
	else if (is_eqoul(cmd[0], "cd") == 1)
		output = ft_cd(cmd[1]);
	else if (is_eqoul(cmd[0], "pwd") == 1)
		output = ft_pwd();
	else if (is_eqoul(cmd[0], "export") == 1)
		output = ft_export(cmd +1);
	else if (is_eqoul(cmd[0], "unset") == 1)
		output = ft_unset(cmd[1]);
	else if (is_eqoul(cmd[0], "env") == 1)
	{
		i = -1;
		while (env[++i])
		{
			output = ft_strjoin (output, env[i]);
			output = ft_strjoin (output, "\n");
		}
	}
	else if (is_eqoul(cmd[0], "exit") == 1)
		return (NULL);
	return (output);
}
