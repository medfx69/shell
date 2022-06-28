/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:13 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/28 15:54:14 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

char **add(char **s1, char *s2)
{
	char **ptr;
	int		i;
	int		j;

	i = -1;
	while(s1[++i]);
	ptr = (char **)malloc(i + 2);
	i = -1;
	while(s1[++i])
		ptr[i] = s1[i];
	ptr[i++] = s2;
	ptr[i] = NULL;
	return (ptr);
}