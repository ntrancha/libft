/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:55:34 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/24 10:12:18 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mem.h"
#include "../../includes/strings.h"

char        **ft_tabstrcpy(char **tab)
{
    char    **new;
    int     len;

    len = 0;
    while (tab[len])
        len++;
    if (!(new = ft_memalloc(sizeof(char*) * (len + 1))))
        return (NULL);
    len = -1;
    while (tab[++len])
        if (!(new[len] = ft_strdup(tab[len])))
            return (NULL);
    new[len] = tab[len];
    return (new);
}
