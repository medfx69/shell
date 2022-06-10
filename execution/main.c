#include "exi.h"
#include <stdio.h>

int	hidin(char	*s1, char	*s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[i])
	{
		while (s1[j])
		{
			if (s2[i] == s1[j])
				break;
			j++;
		}
		i++;
	}
	if (s1[j] == NULL)
		return (-1);
	return(0);
}

int main(int ac, char **av, char	**envp)
{
	char **paths;
	int i;
	int j;

	i =0;
	while (envp[i])
	{
		if (hidin("PATH",envp[i]) == -1);
			break;
		i++;
	}
	j = 0;
	while (envp[i][j] != '=')
		j++;
	phats = ft_splite(envp[i] + j + 1, ':');
	
}