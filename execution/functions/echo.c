/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:42:48 by mait-aad          #+#    #+#             */
/*   Updated: 2022/07/01 16:56:23 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

char	*ft_echo(char	**inputs, int newlin)
{
	int	i;
	char *out;

	i = -1;
	while (inputs[++i])
		out = ft_strjoin(out, inputs[i]);
	if (newlin == 0)
		return (out);
	else
		return (ft_strjoin (out , "\n"));
	return (NULL);
}
