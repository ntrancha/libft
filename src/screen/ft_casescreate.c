/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casescreate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 05:19:35 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:07:09 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"
#include "../../includes/mem.h"

t_case          *ft_casescreate(void)
{
    t_case      *cases;

    cases = ft_memalloc(sizeof(t_case));
    cases->str = NULL;
    cases->spec = NULL;
    cases->next = NULL;
    return (cases);
}
