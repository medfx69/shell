/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 23:42:32 by mait-aad          #+#    #+#             */
/*   Updated: 2022/07/01 19:13:52 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

t_data *next(t_data	*lst)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	lst->next = new;
	new->next = NULL;
	return (new);
}

t_data	*edit_export(void)
{
	int		i;
	t_data	*head;
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
void free_list(t_data *list)
{
	free(list->key);
	free(list->val);
	// free(list->vars[0]);
	// free(list->vars[1]);
	// free(list->vars);
}

char	*ft_export(char	**data)
{
	int		i;
	char	*out;
	t_data	*env_vars;
	
	(void) data;
	out = NULL;
	i = -1;
	while (data[++i]);
	if (i == 0)
	{
		env_vars = edit_export();
		while(env_vars->next != NULL)
		{
			out = ft_strjoin(out, "declare -x ");
			out = ft_strjoin(out, env_vars->key);
			out = ft_strjoin(out, "=\"");
			out = ft_strjoin(out, env_vars->val);
			out = ft_strjoin(out, "\"\n");
			free_list(env_vars);
			env_vars = env_vars->next;
		}
		return (out);
	}
	else
	{
		i = -1;
		while (data[++i])
		{
			// if (chack_var(data[i]))
			printf(">>>  %s\n\n\n\n",data[i]);
			env = add(data[i]);
		}
	}
	return (NULL);
}
