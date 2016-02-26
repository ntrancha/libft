/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:15:45 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/26 15:30:08 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys.h"
#include "../../includes/strings.h"

int         ft_syscmd_func(char *str)
{
    char    *var;
    char    *func;
    char    *options;
    int     index;
    int     count;

    index = 0;
    while (str[index] && (str[index] == ' ' || str[index] == '\t'))
        index++;
    count = index + 1;
    while (str[count] && str[count] != '.')
        count++;
    var = ft_strsub(str, index, count - index);
    index += ++count;
    while (str[index] && str[index] != '(')
        index++;
    func = ft_strsub(str, count, index - count);
    count = index++;
    while (str[count] && str[count] != ')')
        count++;
    options = ft_strsub(str, index, ft_strlen(str) - index - 1);
    count = ft_syscmd_exec(var, func, options);
    ft_strdelth(&var, &func, &options);
    return (count);
}
