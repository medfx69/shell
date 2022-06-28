/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 23:42:32 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/28 15:53:46 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

t_data	*export(char **in, t_data *head, int ac)
{
	int		i;
	t_data	*tmp;

	i = 0;
	head = (t_data *)malloc(sizeof(t_data));
	tmp = head;
	while (env[i])
	{
		tmp->vars = ft_split(env[i], '=');
		tmp->key = tmp->vars[0];
		tmp->val = tmp->vars[1];
		next(tmp);
		tmp = next(tmp);
		i++;
	}
	return (head);
}
