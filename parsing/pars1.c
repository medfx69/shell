/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:01:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/06/10 12:18:58 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char *rm_space(char *s)
{
    int i;
    int len;
    char  *line;

    i = 0;
    len = ft_strlen(s) - 1;
	while(s[i] == ' ' || s[i] == '\t' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\n' || s[i] == '\r')
		i++;
	while(s[len] == ' ' || s[len] == '\t' || s[len] == '\v'
		|| s[len] == '\f' || s[len] == '\n' || s[len] == '\r')
		len--;
    line = (char *)malloc(sizeof(char) * (len - i) + 3);
    if (!(line))
        return (NULL);
    *line = '\0';
    ft_strlcat(line, &s[i], (len - i) + 2);
    return (line);
}

static list_t *set_list(list_t *h, char *s, int *i, int *last, int op)
{
    char *rm_s;
    int x;

    h->n  = 0;
    x = 1;
    // if redirection
    if (op  == (SROUTPUT * 3) || op  == (SRINPUT * 3))
    {
        x = 0;
        (*i)++;
    }
    // else
    else if (op)
        h->n  = op;
    rm_s = (char *)malloc(sizeof(char) * ((*i - *last) + (x + 1)));
    if (!(rm_s))
        return (NULL);
    *rm_s = '\0';
    ft_strlcat(rm_s, &s[*last], (*i - *last) + x);
    h->cmd = rm_space(rm_s);
    free(rm_s);
    *last = *i + 1;
    h->next = malloc(sizeof(list_t));
    if (!(h->next))
        return (NULL);
    /*
        need to chang h->cmd from char* to char**
        and splite and manage cots and duble cots
        and splite with space (all withe space)
        whitout modifing quots contents
    */
    return (h->next);
}

/*
void    cheak_last_op(char *s)
{
    int i;
    while (s[i])
    {
        
        i++;
    }
    if (*s == SIMICOLON)
        // h->n = 0; 
    else if (*s == PIPE)
        // pipe to next; 
    else if (*s == SRINPUT || *s == SROUTPUT
        || ft_strncmp(&s[i], DINPUT, 2) || !ft_strncmp(&s[i], DOUTPUT, 2))
        // bash: syntax error near unexpected token `newline';
        // return (258);
    else if (*s == BACKSLASH)
        // read next ; 
    else if (*s == DOLLAR)
        // ls: $: No such file or directory 
}
*/
static list_t *ft_split_pars(char *s)
{
    int     i;
    list_t  *list;
    list_t  *h;
    int     last;
    
    list = malloc(sizeof(list_t));
    if (!list)
        return (NULL);
    last = 0;
    i = 0;
    h = list;
    while(s[i])
    {
        // cheak_last_op(&s[i]);
        if ((s[i] == SIMICOLON || s[i] == PIPE
            || s[i] == SRINPUT || s[i] == SROUTPUT) 
            && !(s[i + 1] == SRINPUT || s[i + 1] == SROUTPUT))
            h = set_list(h, s, &i, &last, s[i]);
		if (!ft_strncmp(&s[i], DINPUT, 2) || !ft_strncmp(&s[i], DOUTPUT, 2))
            h = set_list(h, s, &i, &last, s[i] * 3);
        i++;
    }
    h = set_list(h, s, &i, &last, 0);
    return (list);
}

list_t *pars_init(char *cmd)
{
    list_t *list;
    char *s;
    int i;
    int quot;

    quot = 0;
    i  = -1;
    while (cmd[++i])
        if (cmd[i] == DOUBLEEQUOT || cmd[i] == SINGLEQUOT)
            quot++;
    if (quot % 2)
    {
        ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
        exit(258);
    }
	s = rm_space(cmd);
    list = ft_split_pars(s);
    free(s);

    return (list);
}

void pars_end(list_t *list)
{
    list_t *h;

    h = list;
    while(h->n)
    {
        free(h->cmd);
        h = h->next;
    }
    free(h->cmd);
    h = list;
    while (h->n)
    {
        h = h->next;
        free(h);
    }
    free(h->next);
    free(list);
}