/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:13 by mait-aad          #+#    #+#             */
/*   Updated: 2022/07/01 19:05:26 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

// static void free_it(char **s)
// {
// 	// int i;

// 	// i = -1;
// 	// while (s[i])
// 	// 	free(s[i]);
// 	free(s);
// }

char **add(char *s2)
{
	char **ptr;
	int		i;

	ptr = NULL;
	i = -1;
	while (env[++i]);
	printf("hello\n");
	ptr = (char **)malloc((i + 2) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = -1;
	while(env[++i])
		ptr[i] = env[i];
	ptr[i++] = s2;
	ptr[i] = NULL;
	free(env);
	return (ptr);
}