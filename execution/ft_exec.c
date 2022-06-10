/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/06/04 18:23:38 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/07 12:01:02 by mait-aad         ###   ########.fr       */
=======
/*   Created: 2022/05/25 10:55:35 by mboukhal          #+#    #+#             */
/*   Updated: 2022/06/05 10:30:59 by mboukhal         ###   ########.fr       */
>>>>>>> 7f851571fc338ca28993697f67270db40ba02878
/*                                                                            */
/* ************************************************************************** */

char	*ft_join_path(char *path, char *cmd)
{
	int		len_p;
	int		len_cmd;
	char	*line;
	int		i;
	int		j;

	len_p = ft_strlen(path);
	len_cmd = ft_strlen(cmd);
	line = malloc(sizeof(char) * (len_p + len_cmd) + 2);
	if (!line)
		return (NULL);
	i = 0;
	j = 0;
	while (path[i])
	{
		line[i] = path[i];
		i++;
	}
	line[i++] = '/';
	while (cmd[j])
		line[i++] = cmd[j++];
	line[i] = '\0';
	return (line);
}

static void	free_it(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

int	it_ecolse(char *s, char	*s2)
{
<<<<<<< HEAD
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s2[i] != s[i])
			return (-1);
	}
	return (0);
}

int	ft_exec(char	**cmd, char	**env)
{
	char	**path_s;
	char	*line;
	int		i;
	int		id;

	path_s = ft_split(getenv("PATH"), ':');
	if (it_ecolse(cmd[0], "echo") == 0)
		ft_echo(cmd, path_s);
	else if (it_ecolse(cmd[0], "cd") == 0)
		ft_cd(cmd, path_s);
	else if (it_ecolse(cmd[0], "pwd") == 0)
		ft_pwd(void);
	else if (it_ecolse(cmd[0], "export") == 0)
		ft_export(cmd, path_s);
	else if (it_ecolse(cmd[0], "unset") == 0)
		ft_unset(cmd, path_s);
	else if (it_ecolse(cmd[0], "env") == 0)
	{
		i = -1;
		while (env[++i])
			printf("%s\n", env[i]);
	}
	else if (it_ecolse(cmd[0], "exit") == 0)
		return (-1);
	i = -1;
	id = 0;
	while (path_s[++i])
	{
		line = ft_join_path(path_s[i], cmd[0]);
		if (!access(line, X_OK))
			break ;
		free(line);
	}
	if (!path_s[i])
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_it(path_s);
		return (0);
	}
	printf("<|%s|>\n", line);
	if (id == 0)
		execve(line, cmd, NULL);
	printf("<|%s|>\n", line);
	id = fork();
	free_it(path_s);
	return (0);
=======
    char    **path_s;
    char    **cmd_s;
    char    *line;
    int     i;
    int     pid;

    i = -1;
    cmd_s = ft_split(cmd, ' ');
    path_s = ft_split(getenv("PATH"), ':');
    while(path_s[++i])
    {
        line = ft_join_path(path_s[i], cmd_s[0]);
        if (!access(line, X_OK))
            break;
        free(line);
    }
    if (!path_s[i])
    {
        ft_putstr_fd("minishell: command not found: ", 2);
        ft_putendl_fd(cmd_s[0], 2);
        free_it(path_s, cmd_s, line);
        return (127);
    }
    pid = fork();
    if (pid < 0)
        return (EXIT_FAILURE);
    if (pid == 0)
        execve(line, cmd_s, NULL);
    waitpid(pid, NULL, 0);
    free_it(path_s, cmd_s, line);
    return (EXIT_SUCCESS);
>>>>>>> 7f851571fc338ca28993697f67270db40ba02878
}
