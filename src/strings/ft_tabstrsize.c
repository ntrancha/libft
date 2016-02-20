/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 13:43:45 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/20 13:46:34 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

int     ft_tabstrsize(char **tab)
{
    int count;
    int ret;

    count = 0;
    ret = 0;
    while (tab[++count])
        ret += (ft_strlen(tab[count]) + 1) * sizeof(char);
    return (ret + (sizeof(char*) * (count + 1)));
}
