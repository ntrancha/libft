/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_echo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:14:07 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/26 09:15:38 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/sys.h"
#include "../../includes/put.h"
#include "../../includes/strings.h"

static int  ft_syscmd_echovar(char *echo)
{
    char    *var;
    char    *cmd;
    int     index;
    int     end;
    
    index = 0;
    end = 0;
    while (echo[++index] && end >= 0)
        if (echo[index] == '{')
        {
            end = index;
            while (echo[end] && echo[end] != '}' && echo[end] != ';')
                end++;
            var = ft_strsub(echo, index + 1, end - index - 1);
            cmd = ft_strjoin(var, ".put();");
            ft_syscmd(cmd);
            ft_strdelt(&var, &cmd);
            return (end);
        }
    return (ft_strlen(echo));
}

void        ft_syscmd_echo(char *str)
{
    char    *echo;
    char    *var;
    char    *cmd;
    int     index;
    int     end;

    echo = ft_strsub(str, 5, ft_strlen(str) - 5);
    index = -1;
    while (echo[++index])
        if (echo[index] == '$' && echo[index + 1] && echo[index + 1] == '{')
            index = ft_syscmd_echovar(echo);
        else if (echo[index] == '$')
        {
            end = index;
            while (echo[end] && echo[end] != ' ' && echo[end] != ';')
                end++;
            var = ft_strsub(echo, index + 1, end - index - 1);
            cmd = ft_strjoin(var, ".put();");
            ft_syscmd(cmd);
            ft_strdelt(&var, &cmd);
            index = end -1;
        }
        else
            ft_putchar(echo[index]);
    ft_strdel(&echo);
}
