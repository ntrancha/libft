/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 21:03:10 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:30:58 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/opt.h"
#include "../../includes/list.h"
#include "../../includes/strings.h"

t_opt      *ft_optget(int argc, char **argv)
{
    t_list  *list;
    int     index;

    list= ft_listcreate();
    if (!list)
        return (NULL);
    index = 0;
    while (++index < argc)
        if (ft_opttest((t_opt*)list, argv[index]) != 1)
            if (!ft_listadd(list, (void *)ft_strdup(argv[index])))
                return (NULL);
    return ((t_opt *)list);
}
