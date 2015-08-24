/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcleanback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 15:39:39 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:49:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

char        *ft_strcleanback(char *str, char c)
{
    char    *tmp;
    int     index;

    index = ft_strlen(str) - 1;
    while (str[index] && str[index] == c)
        index--;
    if (!(tmp = ft_strsub(str, 0, index + 1)))
        return (NULL);
    return (tmp);
}
