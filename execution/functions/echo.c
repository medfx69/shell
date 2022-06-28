#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// int	ft_strlen(char	*s)
// {
// 	int	i;

//    	i = 0;
// 	while(s[i++]);
// 	return (i);
// }

// int	is_eqoul(char	*s1, char	*s2)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while(s1[i])
// 	{
// 		if (s1[i] == s2[j])
// 			j++;
// 		else
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// char	**no_new_line(char	**in, int	pipe, char *l)
// {
// 	int		i;
// 	int		j;
// 	int		c;
// 	char	*tmp;

// 	i = 1;
// 	j = -1;
// 	while(in[++j])
// 	{
// 		if (is_eqoul(in[j], ">"))
// 		{
// 			i = open(in[j + 1], O_CREAT | O_RDWR);
// 			if (i < 0)
// 				return (0);
// 			c = -1;
// 			while (++c < j)
// 			{
// 				tmp = ft_strjoin(tmp, in[c]);
// 			}
// 			tmp = ft_strjoin(tmp, l);
// 			write (i, tmp, ft_strlen(tmp));
// 			return (in[0]);
// 		}
// 	}
// 	j = -1;
// 	while (in[j])
// 		tmp = ft_strjoin(tmp, in[j]);
// 	tmp = ft_strjoin(tmp, l);
// 	if (pipe == 1)
// 		return (tmp);
// 	write(1, tmp, ft_strlen(tmp));
// }


char	*echo(char	*inputs, int newlin, int	pipe)
{
	int	i;
	int	j;
	int	c;

	i = 1;
	j = -1;
	if (newlin == 0)
		return (inputs);
	else
		return (ft_strjoin (inputs , "\n"));
	return (NULL);
}
