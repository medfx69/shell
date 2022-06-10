#include "minishell.h"
int main(int ac, char **av, char **env)
{
	int i;
	i = -1;
		while (env[++i])
			printf("%s\n", env[i]);
}
