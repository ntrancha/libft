/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysfunc_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 20:21:02 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/27 20:09:35 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys.h"
#include "../../includes/sysfunc.h"
#include "../../includes/stack.h"

void    ft_sysfunc_init(void)
{
    ft_tabstr_init();
    ft_str_init();
}
