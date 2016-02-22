/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstr_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 21:25:22 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/22 21:27:35 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sysfunc.h"
#include "../../includes/sys.h"

void    ft_tabstr_init(void)
{
    ft_sysfunc_add("tabstr", "sort", "vv*", ft_tabstrsort_void);
    ft_sysfunc_add("tabstr", "unsort", "vv*", ft_tabstrunsort_void);
}
