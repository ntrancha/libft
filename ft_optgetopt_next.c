/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optgetopt_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 21:07:10 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/28 21:13:25 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char        *ft_optgetopt_next(t_opt *options)
{
    char    *tmp;

    if (!options || !options->start)
        return (NULL);
    tmp = NULL;
    tmp = ft_strdup((char *)options->start->content);
    if (!tmp)
        return (NULL);
    ft_listdelnode((t_list *)options, options->start, ft_memdel);
    return (tmp);
}
