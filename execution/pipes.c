char	ft_pipes(char **cmd)
{
	int	**fd;
	int	pid;
	int	i;
	char	**out;

	fd = malloc(pipes_number);
	i = -1;
	while (++i < pipes_number)
	{
		fd = malloc(2);
		if (!pipe(fd[i]))
			return (0);
	}
	fork();
	pid = getpid();
	if (pid == 0)
		out = ft_exec();
		
}