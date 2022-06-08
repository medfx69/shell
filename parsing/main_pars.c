/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:34:43 by mboukhal          #+#    #+#             */
/*   Updated: 2022/06/08 12:57:31 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// static char *rm_space(char *s)
// {
// 	int i;
// 	int len;
//     char *start;
//     char *r;
	
// 	i = 0;
// 	len = ft_strlen(s);
// 	while (s[i] == ' ')
// 		i++;
//     printf("\t\t\t[%i]|%c|\n", i, s[len]);
// 	if (len > 0)
// 	{
// 		len--;
// 		while (s[len--] == ' ')
// 			;
// 		s[len + 2] = '\0';
// 	}
//     start = (s + (sizeof(char) + i) - 1);
//     printf("[%s] [%d] |%c|\n", start, len, s[len]);
// 	if (i > 0)
//     {
//         r = malloc(sizeof(char) * (len));
//         ft_strlcat(r, start, len);
//         printf("\n\n\t|%s|\t\n\n\n", &s[i]);
//         i = -1;
//         while(r[++i])
//             s[i] = r[i];
//         free(r);
// 	    return (s);
//     }
//     return (s);
// }

int len_c(char *s)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(s[i])
    {
        if (s[i] == SIMICOLON)
            count++;
        i++;
    }
    return (count);
}

char *rm_space(char *s)
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
    if (op  == (SROUTPUT * 3) || op  == (SRINPUT * 3))
    {
        x = 2;
        (*i)++;
    }
    if (op)
    {
        x = 0;
        h->n  = op;
    }
    // x = 2;
    
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
    return (h->next);
}

list_t *ft_split_pars(char *s)
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
        if ((s[i] == SIMICOLON || s[i] == PIPE
            || s[i] == SRINPUT || s[i] == SROUTPUT) 
            && !(//s[i + 1] == SIMICOLON || s[i + 1] == PIPE ||
            s[i + 1] == SRINPUT || s[i + 1] == SROUTPUT))
            h = set_list(h, s, &i, &last, s[i]);
        if (!ft_strncmp(&s[i], "<<", 2) || !ft_strncmp(&s[i], ">>", 2))
            h = set_list(h, s, &i, &last, s[i] * 3);
        i++;
    }
    h = set_list(h, s, &i, &last, 0);
    return (list);
}
