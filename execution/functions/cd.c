/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:47:42 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/28 15:48:20 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

char	*ft_cd(char *dir)
{
	int		i;
	char	*out;
	char	*pwds[2];

	out = NULL;
	pwds[0] = NULL;
	pwds[1] = NULL;
	pwds[0] = getcwd(NULL, 0);
	if (!dir || (dir[0] == '~' && dir[1] == '\0') || dir[0] == '\0')
		chdir(getenv("HOME"));
	else 
	{
		i = chdir(dir);
		if (i == -1)
		{
			out = ft_strjoion("cd: no such file or directory: ", dir);
			return (out);
		}
	}
	pwds[1] = getcwd(NULL, 0);
	mod_env(pwds, env);
	free(pwds[0]);
	free(pwds[1]);
	return (out);
}
