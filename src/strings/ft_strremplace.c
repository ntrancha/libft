/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremplace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 23:47:26 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/27 23:49:06 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

static int  test(char *str, char *old)
{
    int     index;

    index = -1;
    while (str[++index] && old[index])
        if (str[index] != old[index])
            return (0);
    if (old[index] == '\0')
        return (1);
    return (0);
}

char        *ft_strremplace(char *str, char *old, char *new)
{
    char    *ret;
    int     index;
    int     count;

    index = ft_strlen(new) - ft_strlen(old);
    if (!str || !old)
        return (NULL);
    if (ft_strcchr(str, old) == 0)
        return (ft_strdup(str));
    ret = ft_strnew(index + ft_strlen(str) + 1);
    if (!ret)
        return (NULL);
    index = -1;
    while (str && str[++index] && !test(&str[index], old))
        ret[index] = str[index];
    count = -1;
    while (new && new[++count])
        ret[index++] = new[count];
    count = index - count + ft_strlen(old) - 1;
    while (str && str[++count])
        ret[index++] = str[count];
    ret[index] = '\0';
    return (ret);
}
