/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:21:33 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/03 14:22:03 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*ptr;
	char	*str;
	int		i;
	int		j;

	str = (char *)s;
	if (!str)
		return (NULL);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j])
	{
		if (j >= start && i < len)
		{
				ptr[i] = str[j];
				i++;
		}
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}