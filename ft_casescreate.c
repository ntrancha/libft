/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casescreate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 05:19:35 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 05:57:38 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_case          *ft_casescreate(void)
{
    t_case      *cases;

    cases = ft_memalloc(sizeof(t_case));
    cases->str = NULL;
    cases->spec = NULL;
    cases->next = NULL;
    return (cases);
}
