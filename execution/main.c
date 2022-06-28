/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:31:14 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/26 06:33:42 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	hidin(char	*s1, char	*s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[i])
	{
		while (s1[j])
		{
			if (s2[i] == s1[j])
				break;
			j++;
		}
		i++;
	}
	if (s1[j] == '\0')
		return (-1);
	return(0);
}

int main(int ac, char **av, char	**envp)
{
	char **paths;
	int i;
	int j;

	i =0;
	while (envp[i])
	{
		if (hidin("PATH",envp[i]) == -1)
			break;
		i++;
	}
	j = 0;
	while (envp[i][j] != '=')
		j++;
	paths = ft_splite(envp[i] + j + 1, ':');
}