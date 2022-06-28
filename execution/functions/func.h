/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:22:32 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/28 15:54:37 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXI_H
# define EXI_H
# include "../../minishell.h"

typedef struct s_data
{
	char	**vars;
	char	*key;
	char	*val;
	struct s_data *next;
}		t_data;

t_data *next(t_data	*lst)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	lst->next = new;
	new->next = NULL;
	return (new);
}
char	**env;
void	ft_pwd(void);
void	ft_cd(char *dir);
void	mod_env(char	**pwds);
char 	**add(char **s1, char *s2);
t_data	*export(char **in, t_data *head, int ac);
char	*echo(char	*inputs, int newlin, int	pipe);
char	*ft_cd(char *dir, char *output);
char	*add_to_a_file(char	*in, char	file);
char	*create_and_to_a_file(char	*in, char	file);
char	**add(char **s1, char *s2);

#endif