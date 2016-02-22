/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysfunc_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 20:21:02 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/22 21:27:42 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys.h"
#include "../../includes/sysfunc.h"
#include "../../includes/stack.h"

void            ft_sysfunc_init(void)
{
    if (ft_alloc_get("FUNC_TABSTR"))
        ft_tabstr_init();
}
