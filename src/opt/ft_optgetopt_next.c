/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optgetopt_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 21:07:10 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:32:49 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/opt.h"
#include "../../includes/list.h"
#include "../../includes/strings.h"
#include "../../includes/mem.h"

char        *ft_optgetopt_next(t_opt *options)
{
    char    *tmp;

    if (!options || !((t_list*)options)->start)
        return (NULL);
    tmp = NULL;
    tmp = ft_strdup((char *)((t_list*)options)->start->content);
    if (!tmp)
        return (NULL);
    ft_listdelnode((t_list *)options, ((t_list*)options)->start, ft_memdel);
    return (tmp);
}
