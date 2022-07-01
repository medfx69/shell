/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:31:14 by mait-aad          #+#    #+#             */
/*   Updated: 2022/07/01 19:14:40 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"
int main(int ac, char **av,char **envp)
{
	int i;
	int j;
	char *s;

	i = -1;
	(void)ac;
	env = NULL;
	while (envp[++i]);
	env = (char **)malloc((i + 1) * sizeof(char *));
	j = -1;
	while (envp[++j])
		env[j] = envp[j];
	env[j] = NULL;
	s = ft_exec(av+1);
	// printf("%s\n",s);
	i = -1;
	while (env[++i])
		printf("%s\n",env[i]);

	system("leaks minishell");
}