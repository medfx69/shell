/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_and_or_create_to_afile.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:31:02 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/24 17:04:04 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

char	*add_to_a_file(char	*in, char	file)
{
	int		i;
	char	*out;

	if (access(file, W_OK | F_OK) == -1)
	{
		out = ft_strjoin("bash: ", file);
		return (ft_strjoin(out , ": Permission denied"));
	}
	i = open(file, O_RDWR);
	write (i, in, ft_strlen(in));
}

char	*create_and_to_a_file(char	*in, char	file)
{
	int		i;
	char	*out;

	i = open(file, O_CREAT | O_RDWR);
	write (i, in, ft_strlen(in));
	return (in);
}