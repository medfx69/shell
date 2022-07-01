/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:17:13 by mait-aad          #+#    #+#             */
/*   Updated: 2022/07/01 18:08:37 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

char **add_un(char **s1, char *s2)
{
	char **ptr;
	int		i;

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

char	*ft_unset(char	*para)
{
	printf("hello>>%s\n",para);
	return (NULL);
}
