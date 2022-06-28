/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:23:38 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/28 15:47:49 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_it(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

int	it_ecolse(char *s, char	*s2)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s2[i] != s[i])
			return (-1);
	}
	return (0);
}

char	*ft_exec(char	**cmd)
{
	char	**path_s;
	char	*output;
	int		i;

	path_s = ft_split(getenv("PATH"), ':');
	if (it_ecolse(cmd[0], "echo") == 0)
		 output = ft_echo(cmd +1, path_s);
	else if (it_ecolse(cmd[0], "cd") == 0)
		output = ft_cd(cmd +1, output);
	else if (it_ecolse(cmd[0], "pwd") == 0)
		output = ft_pwd(void);
	else if (it_ecolse(cmd[0], "export") == 0)
		output = ft_export(cmd +1, output);
	else if (it_ecolse(cmd[0], "unset") == 0)
		output = ft_unset(env, cmd [1]);
	else if (it_ecolse(cmd[0], "env") == 0)
	{
		i = -1;
		while (env[++i])
			output = ft_strjoin (output, env[i]);
	}
	else if (it_ecolse(cmd[0], "exit") == 0)
		return (output);
}
