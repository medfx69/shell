/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:02:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/06/10 12:14:33 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int    cheak_exit_val(char *cmd)
{
    int i;
    char max[22];
    int len;
    
    i = 0;
    while (cmd[i] == ' ' || cmd[i] == '\n' || cmd[i] == '\t'
        || cmd[i] == '\r' || cmd[i] == '\f')
        i++;
    cmd = &cmd[i];
    if (*cmd == '\0')
        return (0);
    len = ft_strlen(cmd);
    ft_strlcat("9223372036854775807", max, 19);
    i = 0;
    while((cmd[i] <= '9' || cmd[i] >= '0') && cmd[i])
        i++;
    // if (len < 19 && len > 3)
    //     return (255);
    if (len > 19 || i != len)
    {
        ft_putstr_fd("minishell: exit: ", 2);
        ft_putstr_fd(cmd, 2);
        ft_putendl_fd(": numeric argument required", 2);
        return (255);
    }
    else if (len == 19)
    {
        i = 0;
        while((cmd[i] <= '9' || cmd[i] >= '0')
            && max[i] <= cmd[i] && cmd[i])
            i++;
        if (i != len)
            return (255);
    }
    len = ft_atoi(cmd);
    if (len <= 255)
        return ((unsigned int)len);
    else
        return (255);
}

static int loop(char *cmd, char **env)
{
    return (0);
    // char **cmd_p;
    // int i = 0;
    // char s[100];


    // mini->pwd = getcwd(NULL, 0);
    // ft_pwd();
    chdir(getenv("HOME"));
    // printf("%s\n", getcwd(s, 100));
    // printf("|%d|\n", INT32_MAX);

    while (1)
    {
        cmd = readline(PROMPT);
        add_history(cmd);
        ft_exec(cmd);
        // cmd_p = pars(cmd);
        // ft_start(cmd);
        // if (cmd_p != NULL)
        // {
        //     while (cmd_p[i])
        //         free(cmd_p[i++]);
        //     free(cmd_p);
        // }
        if (!ft_strncmp(cmd, "history -c", 10))
            clear_history();
        if (!ft_strncmp(cmd, "exit", 4))
        {
            free(cmd);
            return (cheak_exit_val(&cmd[4]));
        }
        if (!ft_strncmp(cmd, "env", 3))
            ft_env(env);
        if (!ft_strncmp(cmd, "pwd", 3))
            ft_pwd();
        free(cmd);
    }
}


int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    
    // char *line;
    // int i;
    // DIR *dp;
    // struct dirent *dirp;


    // no need to be freed
    // line = getenv("\?");
    // printf("<%s>\n", line);

    // line = getcwd(NULL, 0);
    // printf("|%s|\n", line);
    // free(line);
    // chdir("../..");
    // ft_cd(NULL);

    // ft_exec("ls -l");
    
    // line = getcwd(NULL, 0);
    // printf("|%s|\n", line);
    // free(line);

    // i = isatty(1);
    // printf("|%d|\n", i);
    // line = ttyname(1);
    // printf("|%s|\n", line);
    // free(line);
    // printf("|%d|\n", ttyslot());
    // dp = opendir("utils");
    // if (dp)
    // {
    //     while ((dirp = readdir(dp)) != NULL)
    //         printf("%s\n", dirp->d_name);
    //     printf("\n\n\n\n");
    // }

    // signal(SIGINT, read_line);

    list_t *list;
    list_t *h;
    
    char cmd[] = "   rd ;      rf -t < \"\"\"7777sdf\"\"\"    -dfg> kal | lk << dsdsf >> dsf -l ";
    // char cmd[] = "    ls -a    \"dir\"    ;   cat \"\'\'\'file\'\"";

    printf("\n\n|%s|\n\n\n", cmd);
    list = pars_init(cmd);
    // printf("\n\n\n-----------------\n");
    // printf("|%s|\n", line[1]);

    h = list;
    while(h->n)
    {
        printf("|%s| |%d|\n", h->cmd, h->n);
        h = h->next;
    }
    printf("|%s| |%d|\n\n\n", h->cmd, h->n);

    pars_end(list);
    // end();
    return (loop(cmd, env));
}